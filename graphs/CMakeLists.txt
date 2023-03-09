add_library (
	"graphs"
	"list_weighted_graph.h" "list_weighted_graph.cpp"
	"list_graph.h"
	"graph_algorithms.h"
)

target_link_libraries ("graphs" "mathutil" "data_structures")

add_subdirectory ("tests")