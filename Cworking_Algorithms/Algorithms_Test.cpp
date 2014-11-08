/* Algorithms */
#include "Algorithms_Numeric.h"
#include "Algorithms_TextProcessing.h"
#include "Algorithms_Graphs.h"

/* Asserts */
#include <cassert>
#include <string>
#include <cstdio>
#include <fstream>
#include <iostream>
using namespace std;

/* Euclidian algorithm test */
void euclidian_test()
{
	assert( algorithm_euclidian(4,6) == 2 );
	assert( algorithm_euclidian(-6, 15) == 3 );
	assert( algorithm_euclidian(1841, -392) == 7 );
	assert( algorithm_euclidian(392, 1841) == 7 );
	assert( algorithm_euclidian(-1841, -392) == 7 );
	assert( algorithm_euclidian(421, 111) == 1 );
}

/* Extended euclidian algorithm test */
void extended_euclidian_algorithm_test()
{
	assert( algorithm_extended_euclidian(4,6) == 2 );
	assert( algorithm_extended_euclidian(-6, 15) == 3 );
	assert( algorithm_extended_euclidian(1841, -392) == 7 );
	assert( algorithm_extended_euclidian(392, 1841) == 7 );
	assert( algorithm_extended_euclidian(-1841, -392) == 7 );
	assert( algorithm_extended_euclidian(421, 111) == 1 );
}

/* Prefix - Suffix algorithm test */
void prefix_suffix_algorithm_test()
{
	/* Declare variables */
	string text = "abababababb";
	vector<int> prefix_suffix;

	/* Declare reference */
	int reference[] = { -1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 0 };

	/* Determine prefix suffix array */
	algorithm_prefix_suffix_array( text, prefix_suffix);

	/* Compare with reference */
	for ( unsigned int i = 0; i < text.length() + 1 ; i++ )
	{
		assert( prefix_suffix[i] == reference[i] );
	}
}

/* Max Suffix algorithm test */
void max_suffix_algorithm_test()
{
	/* Declare variables */
	string text = "dababdadad";

	/* Determine prefix suffix array */
	int max_suffix = algorithm_max_suffix( text );

	/* Check result */
	assert( text.substr(max_suffix, text.length() - max_suffix) == "dadad" );

	/* Declare variable */
	text = "abaaba";

	/* Determine max suffix */
	max_suffix = algorithm_max_suffix( text );

	/* Check result */
	assert( text.substr(max_suffix, text.length() - max_suffix) == "baaba" );

	/* Declare variable */
	text = "abaabba";

	/* Determine max suffix */
	max_suffix = algorithm_max_suffix( text );

	/* Check result */
	assert( text.substr(max_suffix, text.length() - max_suffix) == "bba" );
}

void moris_prat_algorithm_test()
{
	/* Declare variables */
	string text = "abcdeffffffffffffffffffffabcd";
	string pattern_1 = "deffffffffff";
	string pattern_2 = "dfa";

	/* Check result */
	assert( algorithm_morris_prat( text, pattern_1 ) == true );
	assert( algorithm_morris_prat( text, pattern_2 ) == false );
}

void knuth_moris_prat_algorithm_test()
{
	/* Declare variables */
	string text = "abcdeffffffffffffffffffffabcd";
	string pattern_1 = "deffffffffff";
	string pattern_2 = "dfa";

	/* Check result */
	assert( algorithm_knuth_morris_prat( text, pattern_1 ) == true );
	assert( algorithm_knuth_morris_prat( text, pattern_2 ) == false );
}

void manacher_algorithm_test()
{
	/* Declare variables */
	string text = "AAABCDDCBADACDDCDD";

	/* Check result */
	assert ( algorithm_manachera_palindrome( text ) == "ABCDDCBA" );
}

void graph_creation_test()
{
	/* Edges */
	vector< Edge > edges;

	/* Line from file */
	int edges_number, vertices_number;

	/* File stream */
	ifstream file;

	/* Open file */
	file.open( "./Files/undirect_graph", ios::in );

	/* Read edges number and vertices number */
	file >> edges_number >> vertices_number;

	/* For each line */
	while ( ! file.eof() )
	{
	    /* Declare vertices */
		string fvertex, svertex;

		/* Declare weight */
		int weight;

		/* Read line */
		file >> fvertex >> svertex >> weight;

		/* Calculate vertex id */
		int fvertex_id = atoi( fvertex.c_str() ) - 1;
		int svertex_id = atoi( svertex.c_str() ) - 1;

		/* Add as edge */
		edges.push_back( Edge( Vertex( fvertex_id, fvertex ),
				               Vertex( svertex_id, svertex ), weight ) );
	}

	/* Close file */
	file.close();

	/* Create Graph */
	Graph graph = Graph( edges );

	/* Print edges weight */
	int edges_id = 0;
	for ( vector< Edge >::const_iterator edge  = graph.get_edges().begin();
			                             edge != graph.get_edges().end(); edge++ )
	{
			assert( edge->get_begin().get_id() == edges[edges_id].get_begin().get_id() );
			assert( edge->get_end().get_id()   == edges[edges_id].get_end().get_id() );
			assert( edge->get_weight()         == edges[edges_id++].get_weight() );
	}

	/* Print vertices */
	int vertex_id = 0;
	for ( vector< Vertex >::const_iterator vertex  = graph.get_vertices().begin();
				                           vertex != graph.get_vertices().end(); vertex++ )
	{
			assert( vertex->get_id() == vertex_id++ );
	}
}

void kruskal_algorith_test()
{
	/* Edges */
	vector< Edge > edges;

	/* Line from file */
	int edges_number, vertices_number;

	/* File stream */
	ifstream file;

	/* Open file */
	file.open( "./Files/undirect_graph", ios::in );

	/* Read edges number and vertices number */
	file >> edges_number >> vertices_number;

	/* For each line */
	while ( ! file.eof() )
	{
		/* Declare vertices */
		string fvertex, svertex;

		/* Declare weight */
		int weight;

		/* Read line */
		file >> fvertex >> svertex >> weight;

		/* Calculate vertex id */
		int fvertex_id = atoi( fvertex.c_str() ) - 1;
		int svertex_id = atoi( svertex.c_str() ) - 1;

		/* Add as edge */
		edges.push_back( Edge( Vertex( fvertex_id, fvertex ),
							   Vertex( svertex_id, svertex ), weight ) );
	}

	/* Close file */
	file.close();

	/* Create Graph */
	Graph graph = Graph( edges );

	/* Run Kruskal algorithm */
	Graph mst = algorithm_minimum_spanning_tree_kruskal( vertices_number, graph );

	/* Reference MST */
	vector< pair<int, int> > reference_mst;

	/* Create reference MST */
	reference_mst.push_back( pair<int, int>(0, 4) );
	reference_mst.push_back( pair<int, int>(0, 5) );
	reference_mst.push_back( pair<int, int>(1, 2) );
	reference_mst.push_back( pair<int, int>(1, 4) );
	reference_mst.push_back( pair<int, int>(3, 4) );

	/* Check the result */
	for ( vector< Edge >::const_iterator edge  = mst.get_edges().begin();
			                             edge != mst.get_edges().end();
			                             edge++ )
	{
		cout << edge->get_begin().get_id() << " " << edge->get_end().get_id() << " " << edge->get_weight() << endl;
	}
}

/* Main function */
int main()
{
	euclidian_test();
	extended_euclidian_algorithm_test();
	prefix_suffix_algorithm_test();
	max_suffix_algorithm_test();
	moris_prat_algorithm_test();
	knuth_moris_prat_algorithm_test();
	manacher_algorithm_test();
	graph_creation_test();
	kruskal_algorith_test();
}
