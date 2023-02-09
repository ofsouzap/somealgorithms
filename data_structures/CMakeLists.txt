add_library (
	"data_structures"
	"queue.h"
	"stack.h"
)

target_link_libraries ("data_structures" "mathutil")

add_subdirectory ("tests")