/**
 * @file Cworking_Signal_Processing_Common_Layer.h
 *
 * @date 18-07-2014
 * @author Kamil Sorokosz
 * @brief File Cworking_Signal_Processing_Common_Layer.h contains ...
 */

#ifndef _CWORKING_SIGNAL_PROCESSING_COMMON_LAYER_H_
#define _CWORKING_SIGNAL_PROCESSING_COMMON_LAYER_H_

#include "MUGED_DSP.h"

/** Aliases for all DSP module types */

/** DSP module */
typedef MUGED_DSP Cworking_DSP;

/** DSP exception */
typedef MUGED_DSPException Cworking_DSP_Exception;

/** Complex matrix */
typedef muged_matrix Cworking_Complex_Matrix;

/** Complex vector */
typedef muged_array Cworking_Complex_Vector;

/** Complex scalar */
typedef muged_scalar Cworking_Complex_Scalar;

/** Matrix data */
typedef struct Cworking_Matrix_Data
{
	/**
	 * Complex matrix
	 * Columns: sub-carriers
	 *    Rows: symbols
	 */
	Cworking_Complex_Vector* cworking_radio_frame;

	/**
	 * Symbols number
	 */
	size_t cworking_symbols;

	/**
	 * Sub-carriers number
	 */
	size_t cworking_subcarriers;

} Cworking_Matrix_Data;


/** PI value */
#define CWORKING_PI 3.14159265

/** OFDM Block size */
#define CWORKING_BLOCK_SIZE 512

/** OFDM symbols */
#define CWORKING_SYMBOLS_NUMBER 14

#endif /* _CWORKING_SIGNAL_PROCESSING_COMMON_LAYER_H_ */
