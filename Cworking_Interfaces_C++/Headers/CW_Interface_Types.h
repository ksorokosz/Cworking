/**
 * @file CW_Interface_Types.h
 *
 * @date 9 mar 2014
 * @author Kamil Sorokosz
 * @brief File contains some standard typedefs
 */

#ifndef _CW_INTERFACE_TYPES_H__
#define _CW_INTERFACE_TYPES_H__

#include "CW_Interface_Definitions.h"

/** Unsigned 32 - bit integer */
typedef unsigned long CW_uint32_t;

/** Unsigned 16 - bit integer */
typedef unsigned int CW_uint16_t;

/** Unsigned 8 - bit integer */
typedef unsigned char CW_uint8_t;

/** Signed 32 - bit integer */
typedef signed long CW_int32_t;

/** Signed 16 - bit integer */
typedef signed int CW_int16_t;

/** Signed 8 - bit integer */
typedef signed char CW_int8_t;

/** Double precision number */
typedef double CW_double;

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

#endif /* _CW_INTERFACE_TYPES_H__ */
