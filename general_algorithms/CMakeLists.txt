add_library (
	"general_algorithms"
	"general_algorithms.h"
	"longest_common_subsequence.cpp"
)

target_link_libraries ("general_algorithms" "mathutil")

add_subdirectory ("tests")