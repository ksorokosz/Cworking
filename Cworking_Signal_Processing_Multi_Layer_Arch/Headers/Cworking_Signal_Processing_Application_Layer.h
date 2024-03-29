/**
 * @file Signal_Processing_UI.h
 *
 * @date 18-07-2014
 * @author Kamil Sorokosz
 * @brief File Signal_Processing_UI.h contains ...
 */

#ifndef _SIGNAL_PROCESSING_UI_H_
#define _SIGNAL_PROCESSING_UI_H_

#include "Cworking_Signal_Processing_Common_Layer.h"

/** Application layer object */
class Cworking_Application_Layer
{
	public:

		/** Application layer processing - Initialize threads */
		void cworking_process_initialize_threads( const Cworking_Thread_Engine_Configuration& cworking_thread_conf );

		/** Application layer processing - OFDM modulation */
		void cworking_process_OFDM_modulation( Cworking_Matrix_Data& cworking_input,
											   Cworking_Matrix_Data& cworking_output );

		/** Application layer processing - OFDM demodulation */
		void cworking_process_OFDM_demodulation( Cworking_Matrix_Data& cworking_input,
												 Cworking_Matrix_Data& cworking_output );

	private:

		/** DSP module */
		Cworking_DSP cworking_dsp;
};

#endif /* _SIGNAL_PROCESSING_UI_H_ */
