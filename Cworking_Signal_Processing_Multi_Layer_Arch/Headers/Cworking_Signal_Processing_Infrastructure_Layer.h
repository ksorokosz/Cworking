/**
 * @file Cworking_Signal_Processing_Infrastructure_Layer.h
 *
 * @date 18-07-2014
 * @author Kamil Sorokosz
 * @brief File Cworking_Signal_Processing_Infrastructure_Layer.h contains ...
 */

#ifndef _CWORKING_SIGNAL_PROCESSING_INFRASTRUCTURE_LAYER_H_
#define _CWORKING_SIGNAL_PROCESSING_INFRASTRUCTURE_LAYER_H_

#include "Cworking_Signal_Processing_Common_Layer.h"


/** Infrastructure layer object */
class Cworking_Infrastructure_Layer
{
	public:

		/** Parse file - input data */
		void cworking_parse_file( const char* cworking_filename, Cworking_Input_Data& cworking_input_data );
};

#endif /* _CWORKING_SIGNAL_PROCESSING_INFRASTRUCTURE_LAYER_H_ */
