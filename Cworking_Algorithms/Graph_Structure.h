/**
 * @file Graph_Structure.h
 *
 * @date 27-10-2014
 * @author Kamil Sorokosz
 * @brief File Graph_Structure.h contains graph data structure
 */

#ifndef _GRAPH_STRUCTURE_H_
#define _GRAPH_STRUCTURE_H_

#include <string>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

/* Vertex */
class Vertex
{
public:

	/* Vertex constructor */
	Vertex( int vertex_id, string vertex_name )
	{
		this->vertex_name = vertex_name;
		this->vertex_id   = vertex_id;
	}

	Vertex( int vertex_id )
	{
		this->vertex_name = "unknown";
		this->vertex_id = vertex_id;
	}

	/* Get vertex ID */
	int get_id() const
	{
		return this->vertex_id;
	}

	/* Get vertex name */
	string get_name() const { return this->vertex_name; }

	/* Comparison operator */
	bool operator<(const Vertex& vertex) const
	{
		return this->vertex_id < vertex.get_id();
	}

	/* Equal operator */
	bool operator==(const Vertex& vertex) const
	{
		return this->vertex_id == vertex.get_id();
	}

	/* Check if vertex is visited */
	bool is_visited()
	{
		return visited;
	}

	/* Set as visited */
	void set_as_visited()
	{
		visited = true;
	}

	/* Set pre-order value */
	void set_pre_order( int id )
	{
		preorder = id;
	}

	/* Set post-order value */
	void set_post_order( int id )
	{
		postorder = id;
	}

private:

	/* Vertex id */
	int vertex_id;

	/* Vertex name */
	string vertex_name;

	/* Visited */
	bool visited;

	/* Pre-Order */
	int preorder;

	/* Post-Order */
	int postorder;
};

/* Edge definition */
class Edge
{
public:

	/* Edge constructor */
	Edge( const Vertex& begin, const Vertex& end, int weight ) : fvertex( begin.get_id(), begin.get_name() ),
	                                                             svertex( end.get_id(), end.get_name() )
	{
		this->weight  = weight;
	}

	Edge( int begin, int end, int weight ) : fvertex( begin ), svertex( end ), weight( weight )
	{

	}

	/* Comparison operator < */
	bool operator<(const Edge& edge) const
	{
		return this->weight < edge.weight ? true : false;
	}

	/* Equal operator */
	bool operator==(const Edge& edge) const
	{
		return this->fvertex == edge.fvertex &&
			   this->svertex == edge.svertex;
	}

	/* Get beginning vertex */
	const Vertex& get_begin() const
	{
		return fvertex;
	}

	/* Get ending vertex */
	const Vertex& get_end() const
	{
		return svertex;
	}

	/* Get weight */
	int get_weight() const
	{
		return weight;
	}

	/* Get reverted edge */
	Edge get_reverted_edge() const
	{
		/* Declare */
		Edge reverted = Edge( this->svertex, this->fvertex, this->weight );

		/* Return reverted edge */
		return reverted;
	}



private:
	/* First vertex */
	Vertex fvertex;

	/* Second vertex */
	Vertex svertex;

	/* Weight */
	int weight;
};

/* Graph class */
class Graph
{
public:

	/* Graph constructor */
	Graph( const vector< Edge >& edges, bool undirected = true );

	/* Get edges from graph */
	const vector< Edge >& get_edges() const;

	/* Get vertices from graph */
	const vector< Vertex >& get_vertices() const;

	/* Get neighbor list */
	const vector< list< Edge > >& get_neighbor_list() const;

	/* Get neighbor matrix */
	const vector< vector< int > >& get_neighbor_matrix() const;

	/* Print graph */
	void print_graph() const;

protected:

	/* Read graph from edges into adjacent list */
	void create_neighbors_matrix( int vertices_number, const vector< Edge >& edges );

	/* Read graph from edges into adjacent matrix */
	void create_neighbors_list( int vertices_number, const vector< Edge >& edges );

private:

	/* Directed or undirected graph */
	bool undirected;

	/* Neighbors matrix */
	vector< vector< int > > neighbors_matrix;

	/* Neighbors list */
	vector< list< Edge > > neighbors_list;

	/* Edges */
	vector< Edge > edges;

	/* Vertices */
	vector< Vertex > vertices;
};

Graph::Graph( const vector< Edge >& edges, bool undirected )
{
	/* Set undirected flag */
	this->undirected = undirected;

	/* Temporary set */
	set< Vertex > tvertices;

	/* For each edge */
	for ( vector< Edge >::const_iterator edge = edges.begin(); edge != edges.end(); edge++ )
	{
		/* Insert vertices */
		tvertices.insert( edge->get_begin() );
		tvertices.insert( edge->get_end() );

		/* Insert edge */
		this->edges.push_back( (*edge ) );
	}

	/* Copy vertices into vector */
	this->vertices.insert(this->vertices.begin(), tvertices.begin(), tvertices.end() );

	/* Create neighbors list */
	create_neighbors_list( this->vertices.size(), edges );

	/* Create neighbors matrix */
	create_neighbors_matrix( this->vertices.size(), edges );
}

/* Get vertices from edges */
inline const vector< Vertex >& Graph::get_vertices() const
{
	return this->vertices;
}

/* Get edges from neighbor list */
inline const vector< Edge >& Graph::get_edges() const
{
	return this->edges;
}

inline void Graph::print_graph() const
{
	int vertex_id = 0;

	/* For each vertex */
	for ( vector< list< Edge > >::const_iterator vertex  = this->neighbors_list.begin();
			                                     vertex != this->neighbors_list.end();
			                                     vertex++ )
	{
		cout << "Vertex " << vertex_id++ << ": ";

		/* For each neighbor */
		for ( list< Edge >::const_iterator neighbor = vertex->begin(); neighbor != vertex->end(); neighbor++ )
		{
			/* Print */
			cout << neighbor->get_end().get_id() << " ";
		}

		cout << endl;
	}
}

/* Return neighbor list */
inline const vector< list< Edge > >& Graph::get_neighbor_list() const
{
	return this->neighbors_list;
}

/* Return neighbor matrix */
inline const vector<vector<int> >& Graph::get_neighbor_matrix() const
{
	return this->neighbors_matrix;
}

/* Read graph from file - neighbor list */
inline void Graph::create_neighbors_list( int vertices_number, const vector< Edge >& edges )
{
	/* Allocate graph */
	this->neighbors_list.resize( vertices_number );

	/* For each edge */
	for ( vector< Edge >::const_iterator edge = edges.begin(); edge != edges.end(); edge++ )
	{
		int beginning = edge->get_begin().get_id();
		int ending    = edge->get_end().get_id();

		/* Directed and undirected graph */
		this->neighbors_list[ beginning ].push_back( (*edge) );

		/* Undirected graph */
		if ( this->undirected )
		{
			/* Create reverted edge */
			this->neighbors_list[ ending ].push_back( edge->get_reverted_edge() );
		}
	}
}

/* Read graph from file - neighbor matrix */
inline void Graph::create_neighbors_matrix( int vertices_number, const vector< Edge >& edges )
{
	/* Allocate graph matrix */
	this->neighbors_matrix.resize(vertices_number);

	/* Initialize rows */
	for ( int vertex_id = 0; vertex_id < vertices_number; vertex_id++ )
		this->neighbors_matrix[vertex_id].resize(vertices_number, 0);

	/* For each edge */
	for ( vector< Edge >::const_iterator edge = edges.begin(); edge != edges.end(); edge++ )
	{
		int beginning = edge->get_begin().get_id();
		int ending    = edge->get_end().get_id();

		/* Directed and undirected graph */
		this->neighbors_matrix[ beginning ][ ending ] = 1;

		/* Undirected graph */
		if ( this->undirected )
		{
			this->neighbors_matrix[ ending ][ beginning ] = 1;
		}
	}
}


#endif /* _GRAPH_STRUCTURE_H_ */
