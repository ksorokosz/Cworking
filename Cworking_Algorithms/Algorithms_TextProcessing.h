/**
 * @file Algorithms_TextProcessing.h
 *
 * @date 25-10-2014
 * @author Kamil Sorokosz
 * @brief File Algorithms_TextProcessing.h contains text processing algorithms
 */

#ifndef _ALGORITHMS_TEXTPROCESSING_H_
#define _ALGORITHMS_TEXTPROCESSING_H_

#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

/** @todo Attention integer number should be changed in case bigger number! */

/* Return maximum value */
inline int algorithm_maximum( int fvalue, int lvalue )
{
	return fvalue > lvalue ? fvalue : lvalue;
}

/* Return minimum value */
inline int algorithm_minimum( int fvalue, int lvalue )
{
	return fvalue > lvalue ? lvalue : fvalue;
}

/* Prefix - Suffix array: linear complexity */
inline void algorithm_prefix_suffix_array( const string& text, vector<int>& array )
{
	/* Initialize array */
	array.clear();
	array.push_back(-1);
	for ( unsigned int j = 0; j < text.length(); j++ )
	{
		array.push_back(0);
	}

	/* Initialize prefix-suffix length */
	int t = -1;

	/* For substring (common beginning) - linear complexity */
	for ( unsigned int j = 1; j < text.length(); j++ )
	{
		while ( t >= 0 && text[ t ] != text[ j - 1 ] )
		{
			t = array[t];
		}
		t++;

		/* Store prefix-suffix length */
		array[ j ] = t;
	}
}

/* Strong prefix-suffix array */
inline void algorithm_strong_prefix_suffix_array( const string& text, vector<int>& array )
{
	/* Initialize array */
	array.clear();
	array.push_back(-1);
	for ( unsigned int j = 0; j < text.length(); j++ )
	{
		array.push_back(0);
	}

	/* Initialize prefix-suffix length */
	int t = -1;

	/* For substring (common beginning) - linear complexity */
	for ( unsigned int j = 1; j < text.length(); j++ )
	{
		while ( t >= 0 && text[ t ] != text[ j - 1 ] )
		{
			t = array[t];
		}
		t++;

		/* Strong prefix-suffix processing part */
		if ( j == text.length() || text[ t ] != text[ j ] )
		{
			array[ j ] = t;
		}
		else
		{
			array[ j ] = array[ t ];
		}
	}
}

/* Max Suffix algorithm */
inline int algorithm_max_suffix( const string& text )
{
	/* Declare max suffix index */
 	int max_suffix = 0;
	int i = 1;
	int p = 1;
	int r = 0;

	while ( i <= (int)text.length() )
	{
		r = ( i - max_suffix ) % p;
		if ( text[ i ] == text[ max_suffix + r ] )
			i++;
		else if ( text[ i ] < text[ max_suffix + r ] )
		{
			i++;
			p = i - max_suffix;
		}
		else
		{
			max_suffix = i - r;
			i = max_suffix + 1;
			p = 1;
		}
	}

	return max_suffix;
}

/* Morris-Prat algorithm */
inline bool algorithm_morris_prat( const string& text, const string& pattern )
{
	/* Declare variables */
	vector<int> array;

	int i, j;
	i = j = 0;

	if ( text.length() <= pattern.length() )
	{
		exit( EXIT_FAILURE );
	}

	/* Calculate prefix-suffix array */
	algorithm_prefix_suffix_array( pattern, array );

	/* For each i */
	while ( i != ( (int)text.length() - (int)pattern.length() ) )
	{
		/* For each pattern sign */
		while ( j < (int)pattern.length() && pattern[j] == text[i+j] )
			j++;

		/* If pattern was found */
		if ( j == (int)pattern.length() )
		{
			return true;
		}

		i = i + j - array[j];
		j = algorithm_maximum( 0, array[j] );
	}

	return false;
}

/* Knuth-Morris-Prat algorithm */
inline bool algorithm_knuth_morris_prat( const string& text, const string& pattern )
{
	/* Declare variables */
	vector<int> array;

	int i, j;
	i = j = 0;

	if ( text.length() <= pattern.length() )
	{
		exit( EXIT_FAILURE );
	}

	/* Calculate prefix-suffix array */
	algorithm_strong_prefix_suffix_array( pattern, array );

	/* For each i */
	while ( i != ( (int)text.length() - (int)pattern.length() ) )
	{
		/* For each pattern sign */
		while ( j < (int)pattern.length() && pattern[j] == text[i+j] )
			j++;

		/* If pattern was found */
		if ( j == (int)pattern.length() )
		{
			return true;
		}

		i = i + j - array[j];
		j = algorithm_maximum( 0, array[j] );
	}

	return false;
}

/* Search for maximum palindrome */
inline string algorithm_manachera_palindrome( const string& text )
{
	/* Declare variables */
	vector< vector<int> > R;
	stringstream buffer;
	string processed_text;

	int palindrom_radius       = 0;
	int max_palindrom_position = 0;
	int max_palindrom_length   = 0;

	/* Add guardians */
	buffer << "@" << text << "#";

	/* Store in string */
	processed_text = buffer.str();

	/* Allocate two rows - for each type */
	R.resize(2);

	/* Initialize array */
	R[0].resize(processed_text.length(), 0);
	R[1].resize(processed_text.length(), 0);

	// even or odd (ABBA or ABCBA)
	for ( int palindrom_type = 0; palindrom_type <= 1; palindrom_type++ )
	{
		R[palindrom_type][0] = palindrom_radius = 0;
		for ( unsigned int counter = 1 ; counter < processed_text.length() - 1; )
		{
			while ( processed_text[ counter + palindrom_radius + palindrom_type ] ==
					processed_text[ counter - palindrom_radius - 1] )
			{
				palindrom_radius++; /* Search maximum palindrom on counter position */
			}

			int palindrom_length = 2 * palindrom_radius + palindrom_type;
			if ( palindrom_length > max_palindrom_length )
			{
				max_palindrom_length   = palindrom_length;
				max_palindrom_position = counter - palindrom_radius - 1;
			}
			R[palindrom_type][counter] = palindrom_radius;

			/* Search other palindroms */
			int small_radius = 1;
			while( small_radius <= palindrom_radius &&
				   R[palindrom_type][counter - small_radius] != palindrom_radius - small_radius)
			{
				R[palindrom_type][counter + small_radius] = algorithm_minimum( R[palindrom_type][counter-small_radius],
						                                                       palindrom_radius - small_radius );
				small_radius++;
			}

			palindrom_radius = algorithm_maximum( palindrom_radius - small_radius, 0 );
			counter         += small_radius;
		}
	}

	/* Get maximum palindrom */
	string maximum_palindrom = text.substr( max_palindrom_position, max_palindrom_length );

	/* All palindroms container */
	vector<string> all_palindroms;

	/* Store all palindroms */
	for(unsigned int counter = 1; counter <= text.length(); counter++)
	{
		for( int palindrom_type = 0; palindrom_type <= 1; palindrom_type++ )
	    	for( int palindrom_radius = R[palindrom_type][counter]; palindrom_radius > 0; palindrom_radius--)
	    	{
	    		int palindrom_length   = 2 * palindrom_radius + palindrom_type;
	    		int palindrom_position = counter - palindrom_radius - 1;

	    		all_palindroms.push_back( text.substr(palindrom_position,palindrom_length) );
	    	}
	}

	return maximum_palindrom;
}


#endif /* _ALGORITHMS_TEXTPROCESSING_H_ */
