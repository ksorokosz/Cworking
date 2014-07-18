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

/** Input data */
typedef struct Cworking_Input_Data
{
	/** Complex vector */
	Cworking_Complex_Vector cworking_vector;

} Cworking_Input_Data;

/** Output data */
typedef struct Cworking_Output_Data
{
	/** Complex vector */
	Cworking_Complex_Vector cworking_vector;

} Cworking_Output_Data;

#endif /* _CWORKING_SIGNAL_PROCESSING_COMMON_LAYER_H_ */
