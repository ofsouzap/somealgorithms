#include "list_graph.h"

using graphs::ListGraph;

graphs::ListGraph::ListGraph(int N) : N(N)
{
	edges = new vector<node_t>[N];
}

graphs::ListGraph::ListGraph(const ListGraph& other)
{

	N = other.N;

	edges = new vector<node_t>[N];

	// Copy edges
	for (int i = 0; i < N; i++)
		for (node_t x : other.edges[i])
			edges[i].push_back(x);

}

graphs::ListGraph::~ListGraph()
{
	delete[] edges;
}

int graphs::ListGraph::get_size() const
{
	return N;
}

void graphs::ListGraph::add_edge(node_t a, node_t b)
{

	if (!node_valid(a) || !node_valid(b))
		throw InvalidNodeException();

	if (is_connected(a, b))
		return;
	else
		edges[a].push_back(b);

}

void graphs::ListGraph::add_edge_undirected(node_t a, node_t b)
{

	if (!node_valid(a) || !node_valid(b))
		throw InvalidNodeException();

	add_edge(a, b);
	add_edge(b, a);

}

bool graphs::ListGraph::is_connected(node_t a, node_t b) const
{

	if (!node_valid(a) || !node_valid(b))
		throw InvalidNodeException();

	return std::find(edges[a].begin(), edges[a].end(), b) != edges[a].end();

}

const vector<graphs::ListGraph::node_t> graphs::ListGraph::neighbours(node_t n) const

{

	if (!node_valid(n))
		throw InvalidNodeException();

	return edges[n];

}
