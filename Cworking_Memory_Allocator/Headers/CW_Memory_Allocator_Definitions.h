/**
 * @file CW_Memory_Allocator_Definitions.h
 *
 * @date 22-05-2014
 * @author Kamil Sorokosz
 * @brief File contains some standard includes and definitions
 */

#ifndef _CW_MEMORY_ALLOCATOR_DEFINITIONS_H__
#define _CW_MEMORY_ALLOCATOR_DEFINITIONS_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

/** Logger tool */
#ifdef DEBUG_MODE
#define LOG(stream, pattern, ...) fprintf( stream,"%20s:%3u | " pattern "\n", __FILE__, __LINE__, ##__VA_ARGS__ );
#else
#define LOG(stream, dummy, ...)
#endif


#endif /* _CW_MEMORY_ALLOCATOR_DEFINITIONS_H__ */
