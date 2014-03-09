#include "CW_Interface_PersonalData.h"

void CW_PersonalData_Init_1( CW_Interface_Body* const CW_interface, CW_Error* const CW_error )
{
	/* Assign appropriate functions to the interface */
	CW_interface->CW_fun     = &CW_PersonalData_CreateFullname_1;
	CW_interface->CW_destroy = &CW_PersonalData_Destroy;

	/* Create error object */
	CW_error->CW_error_code  = EXIT_SUCCESS;
	CW_error->CW_what        = NULL;
}

void CW_PersonalData_Init_2( CW_Interface_Body* const CW_interface, CW_Error* const CW_error )
{
	/* Assign appropriate functions to the interface */
	CW_interface->CW_fun     = &CW_PersonalData_CreateFullname_2;
	CW_interface->CW_destroy = &CW_PersonalData_Destroy;

	/* Create error object */
	CW_error->CW_error_code  = EXIT_SUCCESS;
	CW_error->CW_what        = NULL;
}

void CW_PersonalData_CreateFullname_1( CW_Personal_Data* const CW_data, CW_Error* const CW_error )
{
	snprintf(CW_data->CW_fullname, sizeof( CW_data->CW_fullname ),
			 "%s %s", CW_data->CW_name, CW_data->CW_surname );

	/* Create error object */
	CW_error->CW_error_code  = EXIT_SUCCESS;
	CW_error->CW_what        = NULL;
}

void CW_PersonalData_CreateFullname_2( CW_Personal_Data* const CW_data, CW_Error* const CW_error )
{
	snprintf(CW_data->CW_fullname, sizeof( CW_data->CW_fullname ),
			 "%s %s", CW_data->CW_surname, CW_data->CW_name );

	/* Create error object */
	CW_error->CW_error_code  = EXIT_SUCCESS;
	CW_error->CW_what        = NULL;
}

void CW_PersonalData_Create_Dump( CW_Personal_Data* const CW_data )
{
	/* Clear full name */
	memset( CW_data->CW_fullname, 0, sizeof( CW_data->CW_fullname ) );

	/* Assign name */
	snprintf(CW_data->CW_name, sizeof( CW_data->CW_name ), "Kamil");

	/* Assign surname */
	snprintf(CW_data->CW_surname, sizeof( CW_data->CW_surname ), "Sorokosz");
}

void CW_PersonalData_Destroy( CW_Personal_Data* const CW_data, CW_Error* const CW_error )
{
	/* Nothing to do - no memory dynamically allocated */

	/* Create error object */
	CW_error->CW_error_code  = EXIT_SUCCESS;
	CW_error->CW_what        = NULL;
}
