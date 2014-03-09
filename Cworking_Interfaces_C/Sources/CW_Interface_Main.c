#include "CW_Interface_Main.h"

int main( )
{
	/* Error object */
	CW_Error CW_error;

	/* Interface */
	CW_Interface_Body CW_interface;

	/* Personal data */
	CW_Personal_Data CW_data;

	/* Create personal data */
	CW_PersonalData_Create_Dump( &CW_data );


	/* ----------- Full name = name | ' ' | surname */

	/* Initialize functions */
	CW_interface.CW_init = &CW_PersonalData_Init_1;
	CW_interface.CW_init( &CW_interface, &CW_error );

	/* Run interface function */
	CW_interface.CW_fun( &CW_data, &CW_error );

	/* Print result */
	fprintf( stdout, "%s\n", CW_data.CW_fullname );

	/* Destroy data */
	CW_interface.CW_destroy( &CW_data, &CW_error );


	/* ----------- Full name = surname | ' ' | name */

	/* Initialize functions */
	CW_interface.CW_init = &CW_PersonalData_Init_2;
	CW_interface.CW_init( &CW_interface, &CW_error );

	/* Run interface function */
	CW_interface.CW_fun( &CW_data, &CW_error );

	/* Print result */
	fprintf( stdout, "%s\n", CW_data.CW_fullname );

	/* Destroy data */
	CW_interface.CW_destroy( &CW_data, &CW_error );

	return 0;
}
