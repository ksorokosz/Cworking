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
	Cworking_Matrix_Data cworking_input_data;

	/* Declare modulated data */
	Cworking_Matrix_Data cworking_modulated_data;

	/* Declare output data */
	Cworking_Matrix_Data cworking_output_data;

	/* Initialize input and output data */
	cworking_infrastructure.cworking_allocate_matrix( cworking_input_data  );
	cworking_infrastructure.cworking_allocate_matrix( cworking_modulated_data );
	cworking_infrastructure.cworking_allocate_matrix( cworking_output_data );

	/* Load and parse input file */
	cworking_infrastructure.cworking_create_random_data( cworking_input_data );

	/* Plot chart */
	printf("\n-----------------------Input frame-----------------------\n\n");
	cworking_presentation.cworking_show_data( cworking_input_data );

	/* Run application */
	cworking_application.cworking_process_OFDM_modulation( cworking_input_data, cworking_modulated_data );

	printf("\n-----------------------Modulated frame-----------------------\n\n");
	cworking_presentation.cworking_show_data( cworking_modulated_data );

	/* Run application */
	cworking_application.cworking_process_OFDM_demodulation( cworking_modulated_data, cworking_output_data );

	printf("\n-----------------------Demodulated frame-----------------------\n\n");
	cworking_presentation.cworking_show_data( cworking_output_data );

	/* Clean memory */
	cworking_infrastructure.cworking_delete_matrix( cworking_input_data  );
	cworking_infrastructure.cworking_delete_matrix( cworking_modulated_data );
	cworking_infrastructure.cworking_delete_matrix( cworking_output_data );

	return 0;
}
