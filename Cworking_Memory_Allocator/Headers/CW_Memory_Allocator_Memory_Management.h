/**
 * @file CW_Memory_Allocator_Memory_Management_Definitions.h
 *
 * @date 22-05-2014
 * @author Kamil Sorokosz
 * @brief File contains a simple memory management module
 * Memory pool with fixed-sized blocks
 */

#ifndef _CW_MEMORY_ALLOCATOR_MEMORY_MANAGEMENT_DEFINITIONS_H_
#define _CW_MEMORY_ALLOCATOR_MEMORY_MANAGEMENT_DEFINITIONS_H_

#include "CW_Memory_Allocator_Definitions.h"
#include "CW_Memory_Allocator_Types.h"

/** Memory block occupied */
#define CW_MEMORY_MGMT_BLOCK_OCCUPIED 1

/** Initial variable */
#define CW_MEMORY_MGMT_INIT 0

/** Memory pool structure */
typedef struct CW_Memory_Pool
{
	/** Memory pool */
	void* cw_pool;

	/** Memory pool block size */
	CW_uint32_t cw_pool_block_size;

	/** Number of memory blocks in a pool */
	CW_uint32_t cw_pool_blocks_number;

	/** Current memory block */
	CW_uint32_t cw_current_block;

	/** Number of occupied blocks */
	CW_uint32_t cw_occupied_blocks;

	/** Memory pool size */
	CW_uint32_t cw_pool_size;

	/** Memory pool map */
	CW_uint32_t* cw_pool_block_map;

} CW_Memory_Pool;

/**
 * Allocate memory
 *
 * @param cw_memory_size - memory size
 * @return void* - pointer to memory block
 */
void* CW_allocate_memory( CW_uint32_t cw_memory_size );

/**
 * Free memory
 *
 * @param cw_pointer - pointer to memory block
 */
void CW_free_memory( void** cw_pointer );

/**
 * Create memory pool
 *
 * @param cw_block_size - block size
 * @param cw_memory_pool_size - memory pool size
 * @param cw_memory_pool - pointer to memory pool
 */
void CW_create_memory_pool( CW_uint32_t cw_block_size, CW_uint32_t cw_memory_pool_size, CW_Memory_Pool* const cw_memory_pool );

/**
 * Allocate memory inside memory pool
 *
 * @param cw_memory_pool - memory pool
 * @param cw_memory_size - memory size which will be allocated
 * @return void* - pointer to memory block
 */
void* CW_allocate_memory_from_pool( CW_Memory_Pool* const cw_memory_pool, CW_uint32_t cw_memory_size );

/**
 * Allocate single block in a pool
 *
 * @param cw_memory_pool - memory pool
 * @return void* - pointer to memory block
 */
void* CW_allocate_single_block( CW_Memory_Pool* const cw_memory_pool );

/**
 * Free memory from memory pool
 *
 * @param cw_memory_pool - memory pool
 * @param cw_pointer - pointer which will be free
 */
void CW_free_memory_from_pool( CW_Memory_Pool* const cw_memory_pool, void* cw_pointer );

/**
 * Remove memory pool
 *
 * @param CW_memory_pool - memory pool
 */
void CW_remove_memory_pool( CW_Memory_Pool* const cw_memory_pool );

/** MALLOC macro which should be used instead of malloc */
#define MALLOC( block_type, blocks_number ) (block_type*)CW_allocate_memory( ( blocks_number )* sizeof( block_type ) );

/** FREE macro which should be used instead of free */
#define FREE( pointer ) CW_free_memory( (void**)&pointer );

/** CREATE_MEMORY_POOL macro which should be used instead of CW_create_memory_pool */
#define CREATE_MEMORY_POOL( block_type, blocks_number, memory_pool_address ) CW_create_memory_pool( sizeof( block_type ), ( blocks_number )* sizeof( block_type ), memory_pool_address );

/** MALLOC_STATIC macro which should be used instead of CW_allocate_memory_from_pool */
#define MALLOC_STATIC( memory_pool_address, block_type, blocks_number ) (block_type*)CW_allocate_memory_from_pool( memory_pool_address, (1) * sizeof(block_type) );

/** FREE_STATIC macro which should be used instead of CW_free_memory_from_pool */
#define FREE_STATIC( memory_pool_address, pointer ) CW_free_memory_from_pool( memory_pool_address, pointer );

/** REMOVE_MEMORY_POOL macro which should be used instead of CW_remove_memory_pool */
#define REMOVE_MEMORY_POOL( memory_pool_address ) CW_remove_memory_pool( memory_pool_address );

#endif /* _CW_MEMORY_ALLOCATOR_MEMORY_MANAGEMENT_DEFINITIONS_H_ */
