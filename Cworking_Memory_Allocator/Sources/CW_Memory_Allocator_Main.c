#include "CW_Memory_Allocator_Main.h"

/* Array size */
#define CW_ARRAY_SIZE 10000


int main()
{
	/* Declare simple memory pool */
	CW_Memory_Pool cw_memory_pool;

	/* Memory block */
	CW_uint32_t  cw_block         = 0;

	/* Array */
	CW_uint32_t* array[ CW_ARRAY_SIZE ];

	/* Create memory pool */
	CREATE_MEMORY_POOL(CW_uint32_t, CW_ARRAY_SIZE, &cw_memory_pool );

	/* For each memory block */
	for ( ; cw_block < CW_ARRAY_SIZE; cw_block++ )
	{
		  array[ cw_block ]  = MALLOC_STATIC( &cw_memory_pool, CW_uint32_t, 1 );
		(*array[ cw_block ]) = cw_block;
	}

	/* For each memory block */
	for ( cw_block = 0; cw_block < cw_memory_pool.cw_occupied_blocks; cw_block++ )
	{
		assert( *array[ cw_block ] == cw_block );
	}

	/* For each memory block */
	for ( cw_block = 0; cw_block < cw_memory_pool.cw_occupied_blocks; cw_block++ )
	{
		FREE_STATIC( &cw_memory_pool, array[ cw_block ] );
	}

	/* Remove memory pool */
	REMOVE_MEMORY_POOL( &cw_memory_pool );

	return 0;
}
