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

	/* Declare thread engine configuration */
	Cworking_Thread_Engine_Configuration cworking_thread_conf;

	/* Initialize input and output data */
	cworking_infrastructure.cworking_allocate_matrix( cworking_input_data  );
	cworking_infrastructure.cworking_allocate_matrix( cworking_modulated_data );
	cworking_infrastructure.cworking_allocate_matrix( cworking_output_data );

	/* Create thread engine configuration */
	cworking_infrastructure.cworking_create_thread_configuration( 3, cworking_thread_conf );

	/* Load and parse input file */
	cworking_infrastructure.cworking_create_random_data( cworking_input_data );

	/* Get time - start point */
	double start = omp_get_wtime();

	/* Plot chart */
	printf("\n-----------------------Input frame-----------------------\n\n");
	cworking_presentation.cworking_show_data( cworking_input_data );

	/* Initialize thread engine */
	cworking_application.cworking_process_initialize_threads( cworking_thread_conf );

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

	/* Get time - end point */
	double end = omp_get_wtime();

	/* Print execution time */
	printf("Execution time: %f", end - start);

	return 0;
}
