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
