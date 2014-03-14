#include "CW_Interface_PersonalData.h"

void CW_PersonalData_Create_Dump( CW_Personal_Data* const CW_data )
{
	/* Clear full name */
	memset( CW_data->CW_fullname, 0, sizeof( CW_data->CW_fullname ) );

	/* Assign name */
	snprintf(CW_data->CW_name, sizeof( CW_data->CW_name ), "Kamil");

	/* Assign surname */
	snprintf(CW_data->CW_surname, sizeof( CW_data->CW_surname ), "Sorokosz");
}

void CW_Personal_Data_First::CW_fun(CW_Personal_Data& CW_data)
{
	/* Create Full name as name | ' ' | surname */
	snprintf(CW_data.CW_fullname, sizeof( CW_data.CW_fullname ),
			 "%s %s", CW_data.CW_name, CW_data.CW_surname );
}

void CW_Personal_Data_First::CW_destroy(CW_Personal_Data& CW_data)
{
	/* Nothing to do - no memory dynamically allocated */
}

void CW_Personal_Data_Second::CW_fun(CW_Personal_Data& CW_data)
{
	/* Create Full name as surname | ' ' | name */
	snprintf(CW_data.CW_fullname, sizeof( CW_data.CW_fullname ),
			 "%s %s", CW_data.CW_surname, CW_data.CW_name );
}

void CW_Personal_Data_Second::CW_destroy(CW_Personal_Data& CW_data)
{
	/* Nothing to do - no memory dynamically allocated */
}
