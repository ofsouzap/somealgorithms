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

add_executable ("test_chain_hash_map" "test_chain_hash_map.cpp" )
target_link_libraries ("test_chain_hash_map" "gtest_main" "data_structures")
add_test (
 	NAME "test_chain_hash_map"
 	COMMAND "test_chain_hash_map"
)

add_executable ("test_open_addr_hash_map" "test_open_addr_hash_map.cpp" )
target_link_libraries ("test_open_addr_hash_map" "gtest_main" "data_structures")
add_test (
 	NAME "test_open_addr_hash_map"
 	COMMAND "test_open_addr_hash_map"
)

add_executable ("test_heap_priority_queue" "test_heap_priority_queue.cpp" )
target_link_libraries ("test_heap_priority_queue" "gtest_main" "data_structures")
add_test (
 	NAME "test_heap_priority_queue"
 	COMMAND "test_heap_priority_queue"
)
