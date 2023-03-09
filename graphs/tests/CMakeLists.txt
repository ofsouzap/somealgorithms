add_executable ("test_list_weighted_graph" "test_list_weighted_graph.cpp")
target_link_libraries ("test_list_weighted_graph" "gtest_main" "graphs")
add_test (
	NAME "test_list_weighted_graph"
	COMMAND "test_list_weighted_graph"
)

add_executable ("test_list_graph" "test_list_graph.cpp")
target_link_libraries ("test_list_graph" "gtest_main" "graphs")
add_test (
	NAME "test_list_graph"
	COMMAND "test_list_graph"
)

add_executable ("test_graph_traverse_depth" "test_graph_traverse_depth.cpp")
target_link_libraries ("test_graph_traverse_depth" "gtest_main" "graphs")
add_test (
	NAME "test_graph_traverse_depth"
	COMMAND "test_graph_traverse_depth"
)

add_executable ("test_graph_traverse_breadth" "test_graph_traverse_breadth.cpp")
target_link_libraries ("test_graph_traverse_breadth" "gtest_main" "graphs")
add_test (
	NAME "test_graph_traverse_breadth"
	COMMAND "test_graph_traverse_breadth"
)
