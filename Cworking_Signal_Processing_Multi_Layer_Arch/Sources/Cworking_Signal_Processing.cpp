#include "Cworking_Signal_Processing.h"


/* Main program */
int main()
{
	/* Declare layers */

	/* Infrastructure layer */
	Cworking_Infrastructure_Layer cworking_infrastructure;

	/* Application layer */
	Cworking_Application_Layer cworking_application;

	/* Presentation layer */
	Cworking_Presentation_Layer cworking_presentation;

	/* Declare input data */
	Cworking_Input_Data cworking_input_data;

	/* Declare output data */
	Cworking_Output_Data cworking_output_data;

	/* Load and parse input file */
	cworking_infrastructure.cworking_parse_file( CWORKING_INPUT_FILE, cworking_input_data );

	/* Run application */
	cworking_application.cworking_process_OFDM_modulation( cworking_input_data, cworking_output_data );

	/* Plot chart */
	cworking_presentation.cworking_show_chart( cworking_output_data );

	return 0;
}
