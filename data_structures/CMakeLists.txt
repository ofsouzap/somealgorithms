add_library (
	"data_structures"
	"exceptions.h"
	"queue.h"
	"stack.h"
	"ntree.h"
	"tree_set.h"
	"basic_list_map.h"
	"list_map.h"
)

target_link_libraries ("data_structures" "mathutil")

add_subdirectory ("tests")