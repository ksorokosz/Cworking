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
#include <climits>
#include <cmath>

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
inline Graph algorithm_minimum_spanning_tree_kruskal( const Graph& graph )
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

/* Minimum spanning tree */
inline Graph algorithm_minimum_spanning_tree_prim( const Graph& graph, int start_vertex )
{
	/* Get graph neighboring edges */
	vector< list< Edge > > neighbor_list = graph.get_neighbor_list();

	/* Minimum Spanning Tree */
	vector< long > weights(neighbor_list.size(), INT_MAX);
	vector< bool > flags(neighbor_list.size(), false);
	vector< int > parent(neighbor_list.size(), -1 );
	vector< Edge > minimum_spanning_tree_edges;

	weights[ start_vertex ] = 0;

	/* MST will have all vertices */
	for ( unsigned int i = 0; i < neighbor_list.size(); i++ )
	{
		int minimum = INT_MAX;
		int u;
		// find vertex connected with minimum weight to the tree
		for ( unsigned int j = 0; j < weights.size(); j++ )
		{
			if ( weights[j] < minimum && !flags[j] ) 
			{
				minimum = weights[j];
				u = j;
			}
		}
		flags[u] = true; // added to spanning tree
		if ( parent[u] != -1 ) // update spanning tree
		{
			Edge e(parent[u], u, minimum);
			minimum_spanning_tree_edges.push_back(e);
		}
		
		// for all adjacent vertex update weights
		for ( list< Edge >::const_iterator neighbor = neighbor_list[u].begin(); neighbor != neighbor_list[u].end(); neighbor++ )
		{
			int v = neighbor->get_end().get_id();
			int weight = neighbor->get_weight();
			if ( !flags[v] && weights[v] > weight ) // not in tree and minimum
			{
				weights[v] = weight;
				parent[v] = u;
			}
		}
	}

	/* Create graph from minimum spanning tree */
	Graph minimum_spanning_tree = Graph( minimum_spanning_tree_edges );

	/* Return MST */
	return minimum_spanning_tree;
}

inline void algorithm_bfs( const Graph& graph, int start_vertex, vector<int>& visited_vertices )
{
	/* Declare queue */
	queue< int > queue;

	/* Get graph */
	vector< list< Edge > > neighbor_list = graph.get_neighbor_list();

	/* For each vertex */
	queue.push( start_vertex );
	vector<bool> visited(neighbor_list.size(),0);
	vector<int> distance(neighbor_list.size(),0);

        while ( !queue.empty() )
        {
		int u = queue.front();
		queue.pop();
		visited_vertices.push_back(u);
		for ( list< Edge >::const_iterator neighbor = neighbor_list[u].begin(); neighbor != neighbor_list[u].end(); neighbor++ )
		{
			int v = neighbor->get_end().get_id();
			if ( !visited[v] )
			{
				distance[v] = distance[u] + 1;
				queue.push(v);
				visited[v] = 1;
			}
		}
		visited[u] = 1;
        }
}

inline void algorithm_dfs( const Graph& graph, int start_vertex, vector<int>& visited_vertices )
{
	/* Declare stack */
	vector< int > stack;

	/* Get graph */
	vector< list< Edge > > neighbor_list = graph.get_neighbor_list();

	/* For each vertex */
	stack.push_back( start_vertex );
	vector<bool> visited(neighbor_list.size(),0);
	vector<int> distance(neighbor_list.size(),0);

        while ( !stack.empty() )
        {
		int u = stack.back();
		stack.pop_back();
		visited_vertices.push_back(u);

		visited[u] = 1;
		for ( list< Edge >::const_iterator neighbor = neighbor_list[u].begin(); neighbor != neighbor_list[u].end(); neighbor++ )
		{
			int v = neighbor->get_end().get_id();
			if ( !visited[v] )
			{
				visited[v] = 1;
				distance[v] = distance[u] + 1;
				stack.push_back(v);
			}
		}
        }
}

struct PathPoint {
	int id;
	long distance;
};

struct OrderByDistance
{
    bool operator() (PathPoint const &a, PathPoint const &b) { return a.distance < b.distance; }
};

inline void algorithm_dijkstra( const Graph& graph, int source, vector<int>& shortest_path )
{
	priority_queue<PathPoint, std::vector<PathPoint>, OrderByDistance> queue;

	/* Get graph */
	vector< list< Edge > > neighbor_list = graph.get_neighbor_list();
	vector<long> distances(neighbor_list.size());

	/* Initialize distances from source to vertex to infinity */	
	for ( unsigned int i = 0; i < distances.size(); i++ )
	{
		distances[i] = INT_MAX; // infinity
	}
	distances[source] = 0;

	/* Initialize queue */
	for ( unsigned int i = 0; i < distances.size(); i++ )
	{
		PathPoint pp = { i, distances[i] };
		queue.push(pp);
	}


	while ( !queue.empty() )
	{
		PathPoint u = queue.top(); // get minimum point in terms of distance from the queue
		queue.pop();

		// for each neighbor
		for ( list< Edge >::const_iterator neighbor = neighbor_list[u.id].begin(); neighbor != neighbor_list[u.id].end(); neighbor++ )
		{
			int v = neighbor->get_end().get_id();
			int weight = neighbor->get_weight();
			if ( distances[u.id] != INT_MAX && distances[v] > distances[u.id] + weight )
			{
				distances[v] = distances[u.id] + weight; // update shortest distance
				
				PathPoint pp = { v, distances[v] };
				queue.push(pp);
				
				shortest_path[v] = u.id; // update path
			} 
		}
	}
}

#endif /* _ALGORITHMS_GRAPHS_H_ */
