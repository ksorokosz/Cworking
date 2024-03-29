/**
 * @file CW_Memory_Allocator_Types.h
 *
 * @date 22-05-2014
 * @author Kamil Sorokosz
 * @brief File contains some standard typedefs
 */

#ifndef _CW_MEMORY_ALLOCATOR_TYPES_H__
#define _CW_MEMORY_ALLOCATOR_TYPES_H__

#include "CW_Memory_Allocator_Definitions.h"

/** Unsigned 32 - bit integer */
typedef uint32_t CW_uint32_t;

/** Unsigned 16 - bit integer */
typedef uint16_t CW_uint16_t;

/** Unsigned 8 - bit integer */
typedef uint8_t CW_uint8_t;

/** Signed 32 - bit integer */
typedef int32_t CW_int32_t;

/** Signed 16 - bit integer */
typedef int16_t CW_int16_t;

/** Signed 8 - bit integer */
typedef int8_t CW_int8_t;

/** Double precision number */
typedef double CW_double_t;

/** String type */
typedef char* CW_string_t;

/** Character type */
typedef char CW_char_t;

/** Error structure */
typedef struct CW_Error
{
	/** Error code */
	CW_uint32_t CW_error_code;

	/** Error description */
	CW_string_t CW_what;

} CW_Error;

#endif /* _CW_MEMORY_ALLOCATOR_TYPES_H__ */
