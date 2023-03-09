#pragma once

#include <vector>
#include <algorithm>

#include "exceptions.h"

using std::vector;

namespace graphs
{
	/// @brief Weighted graph data structure implementation using adjacency lists
	class ListWeightedGraph
	{

	public:
		typedef int node_t;

	private:

		struct edge
		{
			node_t other;
			int weight;
		};

		int N;
		vector<edge>* edges;

		bool node_valid(node_t n) const
		{
			return n >= 0 && n < N;
		}

	public:

		ListWeightedGraph(int N);

		ListWeightedGraph(const ListWeightedGraph& other);

		~ListWeightedGraph();

		int get_size() const;

		void add_edge(node_t a, node_t b, int weight);

		void add_edge_undirected(node_t a, node_t b, int weight);

		bool is_connected(node_t a, node_t b) const;

		const vector<node_t> neighbours(node_t n) const;

		int get_weight(node_t a, node_t b) const;

	};
}
