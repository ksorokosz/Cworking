/**
 * @file Algorithms_Graphs.h
 *
 * @date 27-10-2014
 * @author Kamil Sorokosz
 * @brief File Algorithms_Graphs.h contains graphs algorithms
 */

#ifndef _ALGORITHMS_GRAPHS_H_
#define _ALGORITHMS_GRAPHS_H_

/* Graph representation */
#include "Graph_Structure.h"

#include <algorithm>
#include <cstdlib>

using namespace std;

/* Union find */
class Union_Find
{
public:

	/* Create Union Find structure */
	Union_Find( int objects_number )
	{
		this->components_items.resize( objects_number );

		/* Create union find object list */
		for ( int object = 0; object < objects_number; object++ )
		{
			/* Store object in component map */
			this->components_map.push_back( object );

			/* Store component size */
			this->components_sizes.push_back( 1 );

			/* Store object as component item */
			this->components_items[ object ].push_back( object );
		}
	}

	/* Compare objects of two object */
	bool compare( int fobject, int sobject )
	{
		return get_component_id( fobject ) == get_component_id( sobject );
	}

	/* Merge objects of two object */
	void merge( int fobject, int sobject )
	{
		/* Get component id */
		int fcomponent_id = get_component_id( fobject );
		int scomponent_id = get_component_id( sobject );

		/* Compare sizes */
		if ( this->components_sizes[ fcomponent_id ] > this->components_sizes[ scomponent_id ] )
		{
			/* Update size */
			this->components_sizes[ fcomponent_id ] += this->components_sizes[ scomponent_id ];
			this->components_sizes[ scomponent_id ]  = 0;

			/* Update component */
			update_component( sobject, fcomponent_id );
		}
		else
		{
			/* Update size */
			this->components_sizes[ scomponent_id ] += this->components_sizes[ scomponent_id ];
			this->components_sizes[ fcomponent_id ]  = 0;

			/* Update component */
			update_component( fobject, scomponent_id );
		}
	}

protected:

	/* Get component id */
	int get_component_id( int object )
	{
		/* Return component of current object */
		return this->components_map[ object ];
	}

	/* Update component */
	void update_component( int object, int component )
	{
		/* Get old component id */
		int old_component = this->components_map[ object ];

		/* Update elements in old set */
		for ( unsigned int item_index = 0; item_index < this->components_items[ old_component ].size(); item_index++ )
		{
			/* Get item */
			int item = this->components_items[ old_component ][ item_index ];

			/* Update component in map */
			this->components_map[ item ] = component;

			/* Store item in new component set */
			this->components_items[ component ].push_back( item );
		}

		/* Clear old set */
		this->components_items[ old_component ].clear();
	}

private:

	/* Components items */
	vector< vector<int> > components_items;

	/* Components map */
	vector< int > components_map;

	/* Components sizes */
	vector< int > components_sizes;
};

/* Minimum spanning tree */
inline Graph algorithm_minimum_spanning_tree_kruskal( int vertex_number, const Graph& graph )
{
	/* Get graph edges */
	vector< Edge > sorted_edges = graph.get_edges();

	/* Get graph vertices */
	vector< Vertex > vertices   = graph.get_vertices();

	/* Sort edges */
	sort( sorted_edges.begin(), sorted_edges.end() );

	/* Create union find structure */
	Union_Find union_find = Union_Find( vertices.size() );

	/* Minimum Spanning Tree */
	vector< Edge > minimum_spanning_tree_edges;

	/* For each edge in ascending order */
	for ( vector< Edge >::const_iterator edge = sorted_edges.begin();
		  edge != sorted_edges.end(); edge++ )
	{
		/* Get vertices */
		int fvertex = edge->get_begin().get_id();
		int svertex = edge->get_end().get_id();

		/* If inside different components - omit cycles */
		if ( ! union_find.compare( fvertex, svertex ) )
		{
			/* Add to minimum spanning tree */
			minimum_spanning_tree_edges.push_back( (*edge) );

			/* Merge components_map */
			union_find.merge( fvertex, svertex );
		}
	}

	/* Create graph from minimum spanning tree */
	Graph minimum_spanning_tree = Graph( minimum_spanning_tree_edges );

	/* Return MST */
	return minimum_spanning_tree;
}

void algorithm_bfs( const Graph& graph )
{
	/* Declare queue */
	vector< int > queue;

	/* Get graph */
	vector< list< Edge > > neighbor_list = graph.get_neighbor_list();

	/* For each vertex */
	queue.push_back( 0 );

	/* Visit all vertices from queue */
	for ( int i = 0; i < queue.size(); i++ )
	{
		int vertex_id = queue[ i ];
	}

}

void algorithm_dfs( const Graph& graph )
{

}

#endif /* _ALGORITHMS_GRAPHS_H_ */