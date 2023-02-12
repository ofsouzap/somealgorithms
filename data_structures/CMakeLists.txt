add_library (
	"data_structures"
	"queue.h"
	"stack.h"
	"ntree.h"
	"tree_set.h"
)

target_link_libraries ("data_structures" "mathutil")

add_subdirectory ("tests")