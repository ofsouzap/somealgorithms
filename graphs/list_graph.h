#pragma once

#include <vector>
#include <algorithm>

#include "exceptions.h"

using std::vector;

namespace graphs
{
	/// @brief Graph data structure implementation using adjacency lists
	class ListGraph
	{

	public:
		typedef int node_t;

	private:

		int N;
		vector<node_t>* edges;

		bool node_valid(node_t n) const
		{
			return n >= 0 && n < N;
		}

	public:

		ListGraph(int N);

		ListGraph(const ListGraph& other);

		~ListGraph();

		int get_size() const;

		void add_edge(node_t a, node_t b);

		void add_edge_undirected(node_t a, node_t b);

		bool is_connected(node_t a, node_t b) const;

		const vector<node_t> neighbours(node_t n) const;

	};
}
