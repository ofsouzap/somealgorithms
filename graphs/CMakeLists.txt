add_library (
	"graphs"
	"list_graph.h" "list_graph.cpp"
	"graph_algorithms.h"
)

target_link_libraries ("graphs" "mathutil" "data_structures")

add_subdirectory ("tests")