add_library (
	"sorting"
	"sorting.h"
	"insertion_sort.cpp"
	"select_sort.cpp"
	"merge_sort.cpp"
	"heap_sort.cpp"
	"array_swap.cpp"
	"counting_sort.cpp"
	"radix_sort.cpp"
)

target_link_libraries ("sorting" "mathutil")

add_subdirectory ("tests")