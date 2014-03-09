/**
 * @file CW_Interface_PersonalData.h
 *
 * @date 9 mar 2014
 * @author Kamil Sorokosz
 * @brief File contains personal data module which implements example interface
 */

#ifndef _CW_INTERFACE_PERSONALDATA_H__
#define _CW_INTERFACE_PERSONALDATA_H__

#include "CW_Interface_Definitions.h"
#include "CW_Interface_Types.h"
#include "CW_Interface.h"

/**
 * Data required by interface functions
 */
struct CW_Interface_Data
{
	/** User name - it is only an example */
	CW_char_t CW_name[10];

	/** User surname - it is only an example */
	CW_char_t CW_surname[10];

	/** User full name - it is only an example */
	CW_char_t CW_fullname[20];
};

/** Personal data typedef */
typedef struct CW_Interface_Data CW_Personal_Data;

/**
 * Initialize String module. Full name equals name | ' ' | surname
 *
 * @param CW_interface - interface body
 * @param CW_error - error
 */
void CW_PersonalData_Init_1( CW_Interface_Body* const CW_interface, CW_Error* const CW_error );

/**
 * Initialize String module. Full name equals surname | ' ' | name
 *
 * @param CW_interface - interface body
 * @param CW_error - error
 */
void CW_PersonalData_Init_2( CW_Interface_Body* const CW_interface, CW_Error* const CW_error );

/**
 * Create fullname. Full name equals name | ' ' | surname
 *
 * @param CW_data - personal data
 * @param CW_error - error
 */
void CW_PersonalData_CreateFullname_1( CW_Personal_Data* const CW_data, CW_Error* const CW_error );

/**
 * Create fullname. Full name equals surname | ' ' | name
 *
 * @param CW_data - personal data
 * @param CW_error - error
 */
void CW_PersonalData_CreateFullname_2( CW_Personal_Data* const CW_data, CW_Error* const CW_error );

/**
 * Create dump personal data
 *
 * @param CW_data - personal data
 */
void CW_PersonalData_Create_Dump( CW_Personal_Data* const CW_data );

/**
 * Destroy personal data
 *
 * @param CW_data - personal data
 * @param CW_error - error
 */
void CW_PersonalData_Destroy( CW_Personal_Data* const CW_data, CW_Error* const CW_error );

#endif /* _CW_INTERFACE_PERSONALDATA_H__ */
