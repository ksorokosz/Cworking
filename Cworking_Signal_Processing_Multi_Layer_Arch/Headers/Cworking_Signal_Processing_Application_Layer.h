/**
 * @file Signal_Processing_UI.h
 *
 * @date 18-07-2014
 * @author Kamil Sorokosz
 * @brief File Signal_Processing_UI.h contains ...
 */

#ifndef _SIGNAL_PROCESSING_UI_H_
#define _SIGNAL_PROCESSING_UI_H_

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



#endif /* _SIGNAL_PROCESSING_UI_H_ */