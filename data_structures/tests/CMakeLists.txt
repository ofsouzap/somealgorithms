add_executable ("test_queue" "test_queue.cpp" )
target_link_libraries ("test_queue" "gtest_main" "data_structures")
add_test (
 	NAME "test_queue"
 	COMMAND "test_queue"
)

add_executable ("test_stack" "test_stack.cpp" )
target_link_libraries ("test_stack" "gtest_main" "data_structures")
add_test (
 	NAME "test_stack"
 	COMMAND "test_stack"
)

add_executable ("test_ntree" "test_ntree.cpp" )
target_link_libraries ("test_ntree" "gtest_main" "data_structures")
add_test (
 	NAME "test_ntree"
 	COMMAND "test_ntree"
)

add_executable ("test_tree_set" "test_tree_set.cpp" )
target_link_libraries ("test_tree_set" "gtest_main" "data_structures")
add_test (
 	NAME "test_tree_set"
 	COMMAND "test_tree_set"
)

add_executable ("test_basic_list_map" "test_basic_list_map.cpp" )
target_link_libraries ("test_basic_list_map" "gtest_main" "data_structures")
add_test (
 	NAME "test_basic_list_map"
 	COMMAND "test_basic_list_map"
)

add_executable ("test_list_map" "test_list_map.cpp" )
target_link_libraries ("test_list_map" "gtest_main" "data_structures")
add_test (
 	NAME "test_list_map"
 	COMMAND "test_list_map"
)

add_executable ("test_tree_map" "test_tree_map.cpp" )
target_link_libraries ("test_tree_map" "gtest_main" "data_structures")
add_test (
 	NAME "test_tree_map"
 	COMMAND "test_tree_map"
)
