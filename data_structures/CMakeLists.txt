add_library (
	"data_structures"
	"data_structures.cpp"
	"exceptions.h"
	"queue.h"
	"stack.h"
	"basic_list_map.h"
	"list_map.h"
	"tree_map.h"
	"tree_set.h"
	"chain_hash_map.h"
	"open_addr_hash_map.h"
	"heap_priority_queue.h"
)

target_link_libraries ("data_structures" "mathutil")

add_subdirectory ("tests")