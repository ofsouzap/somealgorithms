add_library (
	"data_structures"
	"queue.h"
	"stack.h"
	"ntree.h"
)

target_link_libraries ("data_structures" "mathutil")

add_subdirectory ("tests")