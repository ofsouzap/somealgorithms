#pragma once

#include <vector>

#include "exceptions.h"

using std::vector;

namespace graphs
{
	/// <summary>
	/// Graph data_structure implementation using adjacency lists
	/// </summary>
	template <int N>
	class ListGraph
	{

	public:
		typedef int node_t;

	private:

		vector<node_t> edges[N];

		bool node_valid(node_t n) const
		{
			return n >= 0 && n < N;
		}

	public:

		void add_edge(node_t a, node_t b)
		{

			if (!node_valid(a) || !node_valid(b))
				throw InvalidNodeException();

			if (is_connected(a, b))
				return;
			else
				edges[a].push_back(b);

		}

		void add_edge_undirected(node_t a, node_t b)
		{

			if (!node_valid(a) || !node_valid(b))
				throw InvalidNodeException();

			add_edge(a, b);
			add_edge(b, a);

		}

		bool is_connected(node_t a, node_t b) const
		{

			if (!node_valid(a) || !node_valid(b))
				throw InvalidNodeException();

			return std::find(edges[a].begin(), edges[a].end(), b) != edges[a].end();

		}

		const vector<node_t> neighbours(node_t n) const
		{

			if (!node_valid(n))
				throw InvalidNodeException();

			return edges[n];

		}

	};
}
