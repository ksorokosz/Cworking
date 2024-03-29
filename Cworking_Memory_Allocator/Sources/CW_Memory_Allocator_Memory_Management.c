#include "CW_Memory_Allocator_Memory_Management.h"

void* CW_allocate_memory( CW_uint32_t cw_memory_size )
{
	void* p = NULL;

	/* Allocate memory */
	p = malloc( cw_memory_size );
	if(p == NULL)
	{
		/**
		 * @todo error handling
		 */
		exit(EXIT_FAILURE);
	}

	/* Initialize memory block to zero */
	memset( p, 0, cw_memory_size );

	/* Return memory block */
	return p;
}

void CW_free_memory( void** cw_pointer )
{
	/* Check if not null */
	if ( (*cw_pointer) == NULL )
	{
		/**
		 * @todo error handling
		 */
		exit(EXIT_FAILURE);
	}

	/* Free memory */
	free( (*cw_pointer) );

	/* Reset to NULL */
	( *cw_pointer ) = NULL;
}

void CW_create_memory_pool( CW_uint32_t cw_block_size, CW_uint32_t cw_memory_pool_size, CW_Memory_Pool* const cw_memory_pool )
{
	/* Allocate memory for pool */
	cw_memory_pool->cw_pool = CW_allocate_memory( cw_memory_pool_size );

	/* Initialize memory pool parameters */
	cw_memory_pool->cw_pool_size          = cw_memory_pool_size;
	cw_memory_pool->cw_pool_block_size    = cw_block_size;
	cw_memory_pool->cw_pool_blocks_number = cw_memory_pool_size / cw_block_size;
	cw_memory_pool->cw_current_block      = CW_MEMORY_MGMT_INIT;
	cw_memory_pool->cw_occupied_blocks    = CW_MEMORY_MGMT_INIT;

	/* Memory pool map init */
	cw_memory_pool->cw_pool_block_map     = CW_allocate_memory( sizeof( CW_uint32_t ) * cw_memory_pool->cw_pool_blocks_number );
}

void* CW_allocate_memory_from_pool( CW_Memory_Pool* const cw_memory_pool, CW_uint32_t cw_memory_size )
{
	/* Determine number of blocks which should be allocated */
	CW_uint32_t cw_to_allocate = cw_memory_size / cw_memory_pool->cw_pool_block_size;

	/* Validate block type - it is possible to allocate only 1 block */
	if ( ( cw_memory_size % cw_memory_pool->cw_pool_block_size ) )
	{
		LOG(stderr, "Fractional block number: %d", cw_to_allocate);

		/**
		 * @todo error handling
		 */
		exit( EXIT_FAILURE );
	}

	/* Memory pool is full */
	if ( cw_memory_pool->cw_occupied_blocks + cw_to_allocate > cw_memory_pool->cw_pool_blocks_number )
	{
		return NULL;
	}

	/* Allocate blocks */
	switch( cw_to_allocate )
	{
		case 1: /* Single block */

			/* Allocate single block */
			return CW_allocate_single_block( cw_memory_pool ); break;

		default:
			/**
			 * @todo support more than 1 block in the future
			 */

			/**
			 * @todo error handling
			 */
			exit(EXIT_FAILURE);
	}
}

void* CW_allocate_single_block( CW_Memory_Pool* const cw_memory_pool )
{
	CW_uint32_t cw_block   = CW_MEMORY_MGMT_INIT;
	CW_uint32_t cw_scanned = CW_MEMORY_MGMT_INIT;

	/* Cyclic buffer */
	for ( cw_block = cw_memory_pool->cw_current_block;
		  cw_scanned < cw_memory_pool->cw_pool_blocks_number;
		  cw_scanned++, cw_block++, cw_block %= cw_memory_pool->cw_pool_blocks_number )
	{
		/* If block is free */
		if( cw_memory_pool->cw_pool_block_map[ cw_block ] != CW_MEMORY_MGMT_BLOCK_OCCUPIED )
		{
			/* Set current block */
			cw_memory_pool->cw_current_block = cw_block;

			/* Increment occupied blocks */
			cw_memory_pool->cw_occupied_blocks++;

			/* Set as occupied */
			cw_memory_pool->cw_pool_block_map[ cw_block ] = CW_MEMORY_MGMT_BLOCK_OCCUPIED;

			/* Return pointer to memory block */
			return (CW_uint8_t*)cw_memory_pool->cw_pool + ( cw_block * cw_memory_pool->cw_pool_block_size );
		}
	}

	/* It shouldn't be reached */
	exit( EXIT_FAILURE );
}

void CW_free_memory_from_pool( CW_Memory_Pool* const cw_memory_pool, void* cw_pointer )
{
	/* Calculate block index as the difference with the first element */
	CW_uint32_t cw_block = ( (CW_uint8_t*)cw_pointer - (CW_uint8_t*)cw_memory_pool->cw_pool ) / cw_memory_pool->cw_pool_block_size;

	/* Set as free */
	cw_memory_pool->cw_pool_block_map[ cw_block ] = !CW_MEMORY_MGMT_BLOCK_OCCUPIED;

	/* Decrement occupied blocks */
	cw_memory_pool->cw_occupied_blocks--;
}

void CW_remove_memory_pool( CW_Memory_Pool* const cw_memory_pool )
{
	/* Reset pool parameters */
	cw_memory_pool->cw_pool_size          = CW_MEMORY_MGMT_INIT;
	cw_memory_pool->cw_pool_blocks_number = CW_MEMORY_MGMT_INIT;
	cw_memory_pool->cw_pool_block_size    = CW_MEMORY_MGMT_INIT;
	cw_memory_pool->cw_current_block      = CW_MEMORY_MGMT_INIT;

	/* Free memory pool map */
	CW_free_memory( (void**)&cw_memory_pool->cw_pool_block_map );

	/* Free pool */
	CW_free_memory( (void**)&cw_memory_pool->cw_pool );
}
