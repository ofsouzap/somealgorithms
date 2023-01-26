add_executable ("test_insertion_sort" "sorting_test_util.h" "test_insertion_sort.cpp" )
target_link_libraries ("test_insertion_sort" "gtest_main" "sorting")
add_test (
	NAME "test_insertion_sort"
	COMMAND "test_insertion_sort"
)

add_executable ("test_select_sort" "sorting_test_util.h" "test_select_sort.cpp" )
target_link_libraries ("test_select_sort" "gtest_main" "sorting")
add_test (
	NAME "test_select_sort"
	COMMAND "test_select_sort"
)

add_executable ("test_merge_sort" "sorting_test_util.h" "test_merge_sort.cpp" )
target_link_libraries ("test_merge_sort" "gtest_main" "sorting")
add_test (
	NAME "test_merge_sort"
	COMMAND "test_merge_sort"
)