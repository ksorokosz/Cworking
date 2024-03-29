/**
 * @file CW_Macros_Definitions.h
 *
 * @date 17 mar 2014
 * @author Kamil Sorokosz
 * @brief File contains some useful macros definitions
 */

#ifndef _CW_MACROS_DEFINITIONS_H_
#define _CW_MACROS_DEFINITIONS_H_

#include "CW_Interface_Definitions.h"
#include "CW_Interface_Types.h"

/** Logger tool */
#ifdef DEBUG_MODE
#define LOG(stream, pattern, ...) fprintf( stream,"%20s:%3u | " pattern "\n", __FILE__, __LINE__, ##__VA_ARGS__ )
#else
#define LOG(stream, dummy, ...)
#endif


/** Allocate memory */
void* CW_allocate_memory( CW_uint32_t CW_memory_size, const char* CW_file, CW_uint32_t CW_line );

/** Free memory */
void CW_free_memory( void** CW_pointer, const char* CW_file, CW_uint32_t CW_line );

/** MALLOC macro which should be used instead of malloc */
#define MALLOC( block_type, blocks_number ) (block_type*)CW_allocate_memory( ( blocks_number )* sizeof( block_type ), \
		                                                                     __FILE__, __LINE__ );

/** FREE macro which should be used instead of free */
#define FREE( pointer ) CW_free_memory( (void**)&pointer, __FILE__, __LINE__ );

#endif /* _CW_MACROS_DEFINITIONS_H_ */
