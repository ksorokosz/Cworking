#include "Cworking_Signal_Processing_Presentation_Layer.h"

void Cworking_Presentation_Layer::cworking_show_data( Cworking_Matrix_Data& cworking_matrix )
{
	/* For each symbol */
	for ( size_t cworking_symbol = 0; cworking_symbol < cworking_matrix.cworking_symbols; cworking_symbol++ )
	{
		printf( "Symbol (12 SCs): %d\t", (int)cworking_symbol );
		for ( size_t cworking_subcarrier = 0; cworking_subcarrier < 12; cworking_subcarrier++ )
		{
			/* Get real part of the value */
			double cworking_abs   = cworking_matrix.cworking_radio_frame[ cworking_symbol ].array[ cworking_subcarrier ].muged_abs();

			/* Get imaginary part of the value */
			double cworking_angle = cworking_matrix.cworking_radio_frame[ cworking_symbol ].array[ cworking_subcarrier ].muged_angle();

			/* Print complex value */
			printf( "%f * exp{ %fj }\t", cworking_abs, cworking_angle * 180 / CWORKING_PI );
		}
		printf( "\n" );
	}
}
