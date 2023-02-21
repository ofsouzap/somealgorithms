add_library (
	"graphs"
	"graphs.cpp"
	"list_graph.h"
)

target_link_libraries ("graphs" "mathutil" "data_structures")

add_subdirectory ("tests")