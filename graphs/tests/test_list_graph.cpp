#include <gtest/gtest.h>
#include "list_graph.h"
#include "exceptions.h"

using graphs::ListGraph;
using graphs::InvalidNodeException;

template <class T>
void assert_vector_sets_eq(const vector<T> a, const vector<T> b)
{

	ASSERT_EQ(a.size(), b.size());

	vector<T> remaining;
	for (T x : a) remaining.push_back(x);

	for (int i = 0; i < b.size(); i++)
	{

		T x = b[i];

		auto found = std::find(remaining.begin(), remaining.end(), x);

		ASSERT_NE(found, remaining.end()); // Check value was found

		remaining.erase(found, found + 1); // Erase element from remaining elements

	}

}

TEST(ListGraph, Init)
{
	auto g1 = ListGraph<1>();
	auto g2 = ListGraph<3>();
	auto g3 = ListGraph<20>();
	auto g4 = ListGraph<100>();
}

TEST(ListGraph, AddEdges)
{

	auto g = ListGraph<5>();

	g.add_edge(0, 3);
	g.add_edge(3, 4);
	g.add_edge_undirected(2, 4);
	g.add_edge_undirected(4, 2);
	g.add_edge_undirected(3, 1);

}

TEST(ListGraph, AddEdgesInvalid)
{

	auto g = ListGraph<5>();

	ASSERT_THROW(g.add_edge(5, 0), InvalidNodeException);
	ASSERT_THROW(g.add_edge_undirected(3, 5), InvalidNodeException);

}

TEST(ListGraph, IsConnected)
{

	auto g = ListGraph<5>();

	g.add_edge(0, 3);
	g.add_edge(3, 4);
	g.add_edge_undirected(2, 4);
	g.add_edge_undirected(3, 1);

	for (int a = 0; a < 5; a++)
		for (int b = 0; b < 5; b++)
		{

			bool exp;

			if (a == 0 && b == 3)
				exp = true;
			else if (a == 3 && b == 4)
				exp = true;
			else if (a == 2 && b == 4)
				exp = true;
			else if (a == 4 && b == 2)
				exp = true;
			else if (a == 3 && b == 1)
				exp = true;
			else if (a == 1 && b == 3)
				exp = true;
			else
				exp = false;

			ASSERT_EQ(g.is_connected(a, b), exp);

		}

}

TEST(ListGraph, IsConnectedInvalid)
{

	auto g = ListGraph<5>();

	g.add_edge(0, 3);
	g.add_edge(3, 4);
	g.add_edge_undirected(2, 4);
	g.add_edge_undirected(3, 1);

	ASSERT_THROW(g.is_connected(1, 6), InvalidNodeException);
	ASSERT_THROW(g.is_connected(-5, 2), InvalidNodeException);
	ASSERT_THROW(g.is_connected(-5, 9), InvalidNodeException);
	ASSERT_THROW(g.is_connected(9, -5), InvalidNodeException);
	ASSERT_THROW(g.is_connected(8, 2), InvalidNodeException);
	ASSERT_THROW(g.is_connected(2, -1), InvalidNodeException);

}

TEST(ListGraph, Neighbours)
{

	auto g = ListGraph<5>();

	g.add_edge(0, 3);
	g.add_edge(3, 4);
	g.add_edge_undirected(2, 4);
	g.add_edge_undirected(3, 1);

	vector<int> ns0;
	ns0.push_back(3);

	vector<int> ns1;
	ns1.push_back(3);

	vector<int> ns2;
	ns2.push_back(4);

	vector<int> ns3;
	ns3.push_back(4);
	ns3.push_back(1);

	vector<int> ns4;
	ns4.push_back(2);

	assert_vector_sets_eq(g.neighbours(0), ns0);
	assert_vector_sets_eq(g.neighbours(1), ns1);
	assert_vector_sets_eq(g.neighbours(2), ns2);
	assert_vector_sets_eq(g.neighbours(3), ns3);
	assert_vector_sets_eq(g.neighbours(4), ns4);

}

TEST(ListGraph, NeighboursInvalid)
{

	auto g = ListGraph<5>();

	g.add_edge(0, 3);
	g.add_edge(3, 4);
	g.add_edge_undirected(2, 4);
	g.add_edge_undirected(3, 1);

	ASSERT_THROW(g.neighbours(5), InvalidNodeException);
	ASSERT_THROW(g.neighbours(-1), InvalidNodeException);
	ASSERT_THROW(g.neighbours(10), InvalidNodeException);
	ASSERT_THROW(g.neighbours(-5), InvalidNodeException);

}
