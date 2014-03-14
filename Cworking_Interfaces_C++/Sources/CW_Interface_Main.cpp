#include "CW_Interface_Main.h"

int main()
{
	/* Declare objects */
	CW_Interface_Body* first  = new CW_Personal_Data_First();
	CW_Interface_Body* second = new CW_Personal_Data_Second();
	CW_Personal_Data data;

	/* Create some dump personal data */
	CW_PersonalData_Create_Dump( &data );

	/* Full name = name | ' ' | surname */
	first->CW_fun( data );

	/* Check this */
	fprintf(stdout, "%s\n", data.CW_fullname );

	/* Destroy data */
	first->CW_destroy( data );

	/* Full name = surname | ' ' | name */
	second->CW_fun( data );

	/* Check this */
	fprintf(stdout, "%s\n", data.CW_fullname );

	/* Destroy data */
	first->CW_destroy( data );

	/* Clear memory */
	delete first;
	delete second;

	return 0;
}
