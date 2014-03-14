/**
 * @file CW_Interface.h
 *
 * @date 9 mar 2014
 * @author Kamil Sorokosz
 * @brief File contains example of some interface written in C++
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
 * Interface example - abstract class
 */
class CW_Interface_Body
{

public:

	/**
	 * Default constructor
	 */
	CW_Interface_Body() {};

	/**
	 * Default destructor
	 */
	virtual ~CW_Interface_Body() {};

	/**
	 * Some function
	 *
	 * @param CW_data - shared data
	 */
	virtual void CW_fun( CW_Interface_Data& CW_data ) = 0;

	/**
	 * Destroy shared data
	 *
	 * @param CW_data - shared data
	 * @param CW_error - error
	 */
	virtual void CW_destroy( CW_Interface_Data& CW_data ) = 0;

};

#endif /* _CW_INTERFACE_H__ */
