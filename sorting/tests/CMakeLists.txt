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

add_executable ("test_heap_sort" "sorting_test_util.h" "test_heap_sort.cpp" )
target_link_libraries ("test_heap_sort" "gtest_main" "sorting")
add_test (
	NAME "test_heap_sort"
	COMMAND "test_heap_sort"
)

add_executable ("test_counting_sort" "sorting_test_util.h" "test_counting_sort.cpp" )
target_link_libraries ("test_counting_sort" "gtest_main" "sorting")
add_test (
	NAME "test_counting_sort"
	COMMAND "test_counting_sort"
)

add_executable ("test_radix_sort" "sorting_test_util.h" "test_radix_sort.cpp" )
target_link_libraries ("test_radix_sort" "gtest_main" "sorting")
add_test (
	NAME "test_radix_sort"
	COMMAND "test_radix_sort"
)