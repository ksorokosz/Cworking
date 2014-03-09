/**
 * @file CW_Interface.h
 *
 * @date 9 mar 2014
 * @author Kamil Sorokosz
 * @brief File contains example of some interface written in C
 */

#ifndef _CW_INTERFACE_H__
#define _CW_INTERFACE_H__


#include "CW_Interface_Definitions.h"
#include "CW_Interface_Types.h"

/**
 * Forward declaration of data required by interface functions
 */
struct CW_Interface_Data;

/**
 * Interface example
 */
typedef struct CW_Interface_Body
{
	/**
	 * Initialize interface body
	 *
	 * @param CW_interface - interface body
	 * @param CW_error - error
	 */
	void (*CW_init)( struct CW_Interface_Body* const CW_interface, CW_Error* const CW_error );

	/**
	 * Some function
	 *
	 * @param CW_data - shared data
 	 * @param CW_error - error
	 */
	void (*CW_fun)( struct CW_Interface_Data* const CW_data, CW_Error* const CW_error );

	/**
	 * Destroy shared data
	 *
	 * @param CW_data - shared data
	 * @param CW_error - error
	 */
	void (*CW_destroy)( struct CW_Interface_Data* const CW_data, CW_Error* const CW_error );

} CW_Interface_Body;

#endif /* _CW_INTERFACE_H__ */
