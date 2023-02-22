#pragma once

#include <functional>
#include "stack.h"
#include "queue.h"

#include "list_graph.h"

using std::function;
using data_structures::Stack;
using data_structures::Queue;

namespace graphs
{

	/// @brief Performs a depth-first traversal over the provided graph until stopped
	/// @param g The graph the traverse
	/// @param start The node to start at
	/// @param f The function to run on each node in the order visited. If the function returns true then the traversal will be halted
	void traverse_depth(const ListGraph& g, const ListGraph::node_t start, function<bool(const ListGraph::node_t)> f)
	{

		int N = g.get_size();

		Stack<ListGraph::node_t> stack(N); // N chosen as size since number of elements in the container can't exceed N

		bool* visited = new bool[N];
		for (int i = 0; i < N; i++) visited[i] = false;

		stack.push(start);

		while (!stack.is_empty())
		{

			// Pop node

			auto node = stack.pop();

			// Check if already visited

			if (visited[node])
				continue;

			// Visit node

			f(node);

			// Add children to traverse

			const vector<ListGraph::node_t> neighbours = g.neighbours(node);

			// Go through neighbours in reverse order to allow for the final traversal to be in-order (helps with testing)
			for (int i = neighbours.size() - 1; i >= 0; i--)
			{

				ListGraph::node_t child = neighbours[i];

				// Check if already visited before adding

				if (!visited[child])
					stack.push(child);

			}

			// Set node as visited

			visited[node] = true;

		}

	}


	/// @brief Performs a breadth-first traversal over the provided graph until stopped
	/// @param g The graph the traverse
	/// @param start The node to start at
	/// @param f The function to run on each node in the order visited. If the function returns true then the traversal will be halted
	void traverse_breadth(const ListGraph& g, const ListGraph::node_t start, function<bool(const ListGraph::node_t)> f)
	{

		int N = g.get_size();

		Queue<ListGraph::node_t> queue(N); // N chosen as size since number of elements in the container can't exceed N

		bool* visited = new bool[N];
		for (int i = 0; i < N; i++) visited[i] = false;

		queue.enqueue(start);

		while (!queue.is_empty())
		{

			// Pop node

			auto node = queue.dequeue();

			// Check if already visited

			if (visited[node])
				continue;

			// Visit node

			f(node);

			// Add children to traverse

			const vector<ListGraph::node_t> neighbours = g.neighbours(node);

			for (int i = 0; i < neighbours.size(); i++)
			{

				ListGraph::node_t child = neighbours[i];

				// Check if already visited before adding

				if (!visited[child])
					queue.enqueue(child);

			}

			// Set node as visited

			visited[node] = true;

		}

	}


}
