/**
 * @file Algorithms_Numeric.h
 *
 * @date 25-10-2014
 * @author Kamil Sorokosz
 * @brief File Algorithms_Numeric.h contains numeric algorithms:
 * @brief - euclidian algorithm
 * @brief - extended euclidian algorithm
 */

#ifndef _ALGORITHMS_NUMERIC_H_
#define _ALGORITHMS_NUMERIC_H_

/** @todo Attention integer number should be changed in case bigger number! */

/* Calculate NWD */
inline int algorithm_euclidian(int a, int b)
{
	/* Absolute value for negative numbers */
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;

	/*Declare temporary value */
	int c = 0;

	/* Calculate rests */
	while ( b != 0 )
	{
		/* Module division */
		c = a % b;

		/* Replacing */
		a = b;
		b = c;
	}

	/* Return NWD */
	return a;
}

/* Extended euclidian algorithm */
inline int algorithm_extended_euclidian( int a, int b )
{
	/*Declare temporary values */
	int a_init, b_init;
	int c, quot, r, q, p, s;
	int r_tmp, s_tmp;

	/* Store a and b in separate variables */
	a_init = a; b_init = b;

	/* "a" must be greater than "b" for extended euclidian algorithm */
	a = a > b ? a_init : b_init;
	b = a > b ? b_init : a_init;

	/* Absolute value for negative numbers */
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;

	/* Initialize values */
	c = quot = 0;
	r = q = 0; p = s = 1;

	/* Calculate rests */
	while ( b != 0 )
	{
		/* Modulo division */
		c = a % b;

		/* Integer division */
		quot = a / b;

		/* Replacing */
		a = b; b = c;

		/* Store r, s in temporary */
		r_tmp = r; s_tmp = s;

		/* Update r and s */
		r = p - quot * r;
		s = q - quot * s;

		/* Update p and q */
		p = r_tmp; q = s_tmp;
	}

	/* if "a" is lower than "b" */
	if ( a_init < b_init )
	{
		/* Replace p with q */
		int p_tmp = p;
		p = q;
		q = p_tmp;
	}

	/* Change sings appropriately */
	p = a_init > 0 ? p : -p;
	q = b_init > 0 ? q : -q;

	/* Return NWD */
	return p * a_init + q * b_init;
}

#endif /* _ALGORITHMS_NUMERIC_H_ */
