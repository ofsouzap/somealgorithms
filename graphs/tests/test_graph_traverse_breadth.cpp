#include <gtest/gtest.h>
#include "list_graph.h"
#include "graph_algorithms.h"

using std::function;
using graphs::ListGraph;
using graphs::traverse_breadth;

template <class T>
void assert_vector_eq(vector<T> a, vector<T> b)
{

	ASSERT_EQ(a.size(), b.size());

	for (int i = 0; i < a.size(); i++)
	{
		ASSERT_EQ(a[i], b[i]);
	}

}

TEST(GraphTraverseBreadth, SingleNode)
{

	ListGraph g(1);

	vector<ListGraph::node_t> exp_out;
	exp_out.push_back(0);

	vector<ListGraph::node_t> out;

	function<bool(ListGraph::node_t)> f = [&out](auto node) { out.push_back(node); return false; };
	traverse_breadth(g, 0, f);

	assert_vector_eq(exp_out, out);

}

TEST(GraphTraverseBreadth, TreeGraphDirected)
{

	ListGraph g(5);

	g.add_edge(0, 1);
	g.add_edge(1, 2);
	g.add_edge(2, 3);
	g.add_edge(3, 4);

	vector<ListGraph::node_t> exp_out;
	exp_out.push_back(0);
	exp_out.push_back(1);
	exp_out.push_back(2);
	exp_out.push_back(3);
	exp_out.push_back(4);

	vector<ListGraph::node_t> out;

	function<bool(ListGraph::node_t)> f = [&out](auto node) { out.push_back(node); return false; };
	traverse_breadth(g, 0, f);

	assert_vector_eq(exp_out, out);

}

TEST(GraphTraverseBreadth, TreeGraphUndirected)
{

	ListGraph g(5);

	g.add_edge_undirected(0, 1);
	g.add_edge_undirected(1, 2);
	g.add_edge_undirected(2, 3);
	g.add_edge_undirected(3, 4);

	vector<ListGraph::node_t> exp_out;
	exp_out.push_back(0);
	exp_out.push_back(1);
	exp_out.push_back(2);
	exp_out.push_back(3);
	exp_out.push_back(4);

	vector<ListGraph::node_t> out;

	function<bool(ListGraph::node_t)> f = [&out](auto node) { out.push_back(node); return false; };
	traverse_breadth(g, 0, f);

	assert_vector_eq(exp_out, out);

}

TEST(GraphTraverseBreadth, StarGraphDirected)
{

	ListGraph g(13);

	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(0, 4);
	g.add_edge(0, 7);

	g.add_edge(2, 3);

	g.add_edge(4, 5);
	g.add_edge(4, 6);

	g.add_edge(7, 8);
	g.add_edge(8, 9);
	g.add_edge(8, 10);
	g.add_edge(10, 11);
	g.add_edge(10, 12);

	vector<ListGraph::node_t> exp_out;
	exp_out.push_back(0);
	exp_out.push_back(1);
	exp_out.push_back(2);
	exp_out.push_back(4);
	exp_out.push_back(7);
	exp_out.push_back(3);
	exp_out.push_back(5);
	exp_out.push_back(6);
	exp_out.push_back(8);
	exp_out.push_back(9);
	exp_out.push_back(10);
	exp_out.push_back(11);
	exp_out.push_back(12);

	vector<ListGraph::node_t> out;

	function<bool(ListGraph::node_t)> f = [&out](auto node) { out.push_back(node); return false; };
	traverse_breadth(g, 0, f);

	assert_vector_eq(exp_out, out);

}

TEST(GraphTraverseBreadth, StarGraphUndirected)
{

	ListGraph g(13);

	g.add_edge_undirected(0, 1);
	g.add_edge_undirected(0, 2);
	g.add_edge_undirected(0, 4);
	g.add_edge_undirected(0, 7);

	g.add_edge_undirected(2, 3);

	g.add_edge_undirected(4, 5);
	g.add_edge_undirected(4, 6);

	g.add_edge_undirected(7, 8);
	g.add_edge_undirected(8, 9);
	g.add_edge_undirected(8, 10);
	g.add_edge_undirected(10, 11);
	g.add_edge_undirected(10, 12);

	vector<ListGraph::node_t> exp_out;
	exp_out.push_back(0);
	exp_out.push_back(1);
	exp_out.push_back(2);
	exp_out.push_back(4);
	exp_out.push_back(7);
	exp_out.push_back(3);
	exp_out.push_back(5);
	exp_out.push_back(6);
	exp_out.push_back(8);
	exp_out.push_back(9);
	exp_out.push_back(10);
	exp_out.push_back(11);
	exp_out.push_back(12);

	vector<ListGraph::node_t> out;

	function<bool(ListGraph::node_t)> f = [&out](auto node) { out.push_back(node); return false; };
	traverse_breadth(g, 0, f);

	assert_vector_eq(exp_out, out);

}

TEST(GraphTraverseBreadth, GeneralDirected)
{

	ListGraph g(8);

	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(2, 0);
	g.add_edge(0, 6);

	g.add_edge(1, 5);

	g.add_edge(5, 6);
	g.add_edge(6, 5);

	g.add_edge(7, 6);

	g.add_edge(2, 3);
	g.add_edge(3, 2);
	g.add_edge(2, 4);
	g.add_edge(4, 3);

	vector<ListGraph::node_t> exp_out;
	exp_out.push_back(0);
	exp_out.push_back(1);
	exp_out.push_back(2);
	exp_out.push_back(6);
	exp_out.push_back(5);
	exp_out.push_back(3);
	exp_out.push_back(4);

	vector<ListGraph::node_t> out;

	function<bool(ListGraph::node_t)> f = [&out](auto node) { out.push_back(node); return false; };
	traverse_breadth(g, 0, f);

	assert_vector_eq(exp_out, out);

}

TEST(GraphTraverseBreadth, GeneralUndirected)
{

	ListGraph g(8);

	g.add_edge_undirected(0, 1);
	g.add_edge_undirected(0, 2);
	g.add_edge_undirected(0, 6);

	g.add_edge_undirected(1, 5);

	g.add_edge_undirected(5, 6);

	g.add_edge_undirected(7, 6);

	g.add_edge_undirected(2, 3);
	g.add_edge_undirected(2, 4);
	g.add_edge_undirected(4, 3);

	vector<ListGraph::node_t> exp_out;
	exp_out.push_back(0);
	exp_out.push_back(1);
	exp_out.push_back(2);
	exp_out.push_back(6);
	exp_out.push_back(5);
	exp_out.push_back(3);
	exp_out.push_back(4);
	exp_out.push_back(7);

	vector<ListGraph::node_t> out;

	function<bool(ListGraph::node_t)> f = [&out](auto node) { out.push_back(node); return false; };
	traverse_breadth(g, 0, f);

	assert_vector_eq(exp_out, out);

}
