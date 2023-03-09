#include "list_weighted_graph.h"

using graphs::ListWeightedGraph;

graphs::ListWeightedGraph::ListWeightedGraph(int N) : N(N)
{
	edges = new vector<edge>[N];
}

graphs::ListWeightedGraph::ListWeightedGraph(const ListWeightedGraph& other)
{

	N = other.N;

	edges = new vector<edge>[N];

	// Copy edges
	for (int i = 0; i < N; i++)
		for (edge e : other.edges[i])
			edges[i].push_back(e);

}

graphs::ListWeightedGraph::~ListWeightedGraph()
{
	delete[] edges;
}

int graphs::ListWeightedGraph::get_size() const
{
	return N;
}

void graphs::ListWeightedGraph::add_edge(node_t a, node_t b, int weight)
{

	if (!node_valid(a) || !node_valid(b))
		throw InvalidNodeException();

	if (is_connected(a, b))
		return;
	else
		edges[a].push_back({ b, weight });

}

void graphs::ListWeightedGraph::add_edge_undirected(node_t a, node_t b, int weight)
{

	if (!node_valid(a) || !node_valid(b))
		throw InvalidNodeException();

	add_edge(a, b, weight);
	add_edge(b, a, weight);

}

bool graphs::ListWeightedGraph::is_connected(node_t a, node_t b) const
{

	if (!node_valid(a) || !node_valid(b))
		throw InvalidNodeException();

	return std::find_if(edges[a].begin(), edges[a].end(), [b](edge e) { return e.other == b; }) != edges[a].end();

}

const vector<graphs::ListWeightedGraph::node_t> graphs::ListWeightedGraph::neighbours(node_t n) const

{

	if (!node_valid(n))
		throw InvalidNodeException();

	vector<graphs::ListWeightedGraph::node_t> ns(edges[n].size());

	for (int i = 0; i < edges[n].size(); i++)
	{
		ns[i] = edges[n][i].other;
	}

	return ns;

}

int graphs::ListWeightedGraph::get_weight(node_t a, node_t b) const
{

	auto res = std::find_if(edges[a].begin(), edges[a].end(), [b](edge e) { return e.other == b; });

	if (res == edges[a].end())
		throw NoEdgeFoundException();
	else
		return res->weight;

}
