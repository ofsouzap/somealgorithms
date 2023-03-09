#pragma once

#include "list_weighted_graph.h"

namespace graphs
{
	/// @brief Unweighted graph data structure implementation using adjacency lists
	class ListGraph : protected ListWeightedGraph
	{

		// N.B. this is just a weighted graph with all the weights set to 1

	public:

		typedef ListWeightedGraph::node_t node_t;

		ListGraph(int N) : ListWeightedGraph(N)
		{
		}

		ListGraph(const ListGraph& other) : ListWeightedGraph(other)
		{
		}

		int get_size() const
		{
			return ListWeightedGraph::get_size();
		}

		void add_edge(node_t a, node_t b)
		{
			ListWeightedGraph::add_edge(a, b, 1);
		}

		void add_edge_undirected(node_t a, node_t b)
		{
			ListWeightedGraph::add_edge_undirected(a, b, 1);
		}

		bool is_connected(node_t a, node_t b) const
		{
			return ListWeightedGraph::is_connected(a, b);
		}

		const vector<node_t> neighbours(node_t n) const
		{
			return ListWeightedGraph::neighbours(n);
		}

	};
}
