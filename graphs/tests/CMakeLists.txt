add_executable ("test_list_graph" "test_list_graph.cpp")
target_link_libraries ("test_list_graph" "gtest_main" "graphs")
add_test (
	NAME "test_list_graph"
	COMMAND "test_list_graph"
)
