#include "Cworking_Signal_Processing_Infrastructure_Layer.h"

void Cworking_Infrastructure_Layer::cworking_allocate_matrix( Cworking_Matrix_Data& cworking_matrix )
{
	/* Symbols number */
	cworking_matrix.cworking_symbols     = CWORKING_SYMBOLS_NUMBER;

	/* Sub-carriers number */
	cworking_matrix.cworking_subcarriers = CWORKING_BLOCK_SIZE;

	/* Create frame */
	cworking_matrix.cworking_radio_frame = new Cworking_Complex_Vector[ cworking_matrix.cworking_symbols ];

	/* Initialize each block and symbol */
	for ( size_t cworking_symbol = 0; cworking_symbol < cworking_matrix.cworking_symbols; cworking_symbol++ )
	{
			/* Allocate memory */
			cworking_matrix.cworking_radio_frame[ cworking_symbol ].array =
					               new Cworking_Complex_Scalar[ cworking_matrix.cworking_subcarriers ];

			/* Store size */
			cworking_matrix.cworking_radio_frame[ cworking_symbol ].length = cworking_matrix.cworking_subcarriers;

			/* Initialize memory */
			for ( size_t cworking_subcarrier = 0; cworking_subcarrier < cworking_matrix.cworking_subcarriers; cworking_subcarrier++ )
			{
				/* Initialize to 0 */
				cworking_matrix.cworking_radio_frame[ cworking_symbol ].array[ cworking_subcarrier ] = MUGED_Complex( 0, 0 );
			}
	}
}

void Cworking_Infrastructure_Layer::cworking_create_random_data( Cworking_Matrix_Data& cworking_input_data )
{
	/* Possible angles */
	double cworking_possible_angles[ 4 ] = { 45, 135, 225, 315 };

	/* For each block and half symbols */
	for ( size_t cworking_symbol = 0; cworking_symbol < cworking_input_data.cworking_symbols / 2; cworking_symbol++ )
	{
		for ( size_t cworking_subcarrier = 0; cworking_subcarrier < cworking_input_data.cworking_subcarriers; cworking_subcarrier++ )
		{
			/* Angle - 135 degrees */
			double cworking_angle = cworking_possible_angles[ cworking_subcarrier % 4 ];

			/*
			 * QPSK symbols
			 * Each could be written as 1 * exp(-j*angle), where angle equals: 45, 135, 225, 315
			 */
			Cworking_Complex_Scalar cworking_qpsk_symbol = MUGED_Complex( 1, cworking_angle * CWORKING_PI / 180 , false );

			/* Store QPSK symbol */
			cworking_input_data.cworking_radio_frame[ cworking_symbol ].array[ cworking_subcarrier ] = cworking_qpsk_symbol;
		}
	}
}

void Cworking_Infrastructure_Layer::cworking_create_thread_configuration( int cworking_cores_number,
		                                                                  Cworking_Thread_Engine_Configuration& cworking_thread_conf )
{
	/* Set cores number */
	cworking_thread_conf.cworking_cores_number = cworking_cores_number;
}

void Cworking_Infrastructure_Layer::cworking_delete_matrix( Cworking_Matrix_Data& cworking_matrix )
{
	/* Clear memory */
	for ( size_t cworking_symbol = 0; cworking_symbol < cworking_matrix.cworking_symbols; cworking_symbol++ )
	{
		delete [] cworking_matrix.cworking_radio_frame[ cworking_symbol ].array;
	}
	delete [] cworking_matrix.cworking_radio_frame;
}

