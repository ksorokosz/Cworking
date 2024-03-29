#include "Cworking_Signal_Processing_Application_Layer.h"

void Cworking_Application_Layer::cworking_process_OFDM_modulation( Cworking_Matrix_Data& cworking_input, Cworking_Matrix_Data& cworking_output )
{
	/* For each symbol */
	#pragma omp parallel for
	for ( size_t cworking_symbol = 0; cworking_symbol < cworking_input.cworking_symbols; cworking_symbol++ )
	{
		/* Create temporary symbol vector */
		Cworking_Complex_Vector cworking_symbol_output;

		/* ------------------------ OFDM Modulation ------------------------ */

		/* Calculate IFFT */
		this->cworking_dsp.muged_1D_ifft( cworking_input.cworking_radio_frame[ cworking_symbol ], cworking_symbol_output );

		/* ------------------------ OFDM Modulation ------------------------ */

		/* Store output into matrix */
		for ( size_t cworking_subcarrier = 0; cworking_subcarrier < cworking_symbol_output.length; cworking_subcarrier++ )
		{
			/* Store single sub-carrier */
			cworking_output.cworking_radio_frame[ cworking_symbol ].array[ cworking_subcarrier ] =
															 cworking_symbol_output.array[ cworking_subcarrier ];
		}

		/* Clean memory */
		delete [] cworking_symbol_output.array;
	}
}

void Cworking_Application_Layer::cworking_process_initialize_threads( const Cworking_Thread_Engine_Configuration& cworking_thread_conf )
{
	/* Set number of threads */
	omp_set_num_threads( cworking_thread_conf.cworking_cores_number );
}

void Cworking_Application_Layer::cworking_process_OFDM_demodulation( Cworking_Matrix_Data& cworking_input, Cworking_Matrix_Data& cworking_output )
{
	/* For each symbol */
	#pragma omp parallel for
	for ( size_t cworking_symbol = 0; cworking_symbol < cworking_input.cworking_symbols; cworking_symbol++ )
	{
		/* Create temporary symbol vector */
		Cworking_Complex_Vector cworking_symbol_output;

		/* ------------------------ OFDM DeModulation ------------------------ */

		/* Calculate IFFT */
		this->cworking_dsp.muged_1D_fft( cworking_input.cworking_radio_frame[ cworking_symbol ], cworking_symbol_output );

		/* ------------------------ OFDM DeModulation ------------------------ */

		/* Store output into matrix */
		for ( size_t cworking_subcarrier = 0; cworking_subcarrier < cworking_symbol_output.length; cworking_subcarrier++ )
		{
			/* Store single sub-carrier */
			cworking_output.cworking_radio_frame[ cworking_symbol ].array[ cworking_subcarrier ] =
															 cworking_symbol_output.array[ cworking_subcarrier ];
		}

		/* Clean memory */
		delete [] cworking_symbol_output.array;
	}
}
