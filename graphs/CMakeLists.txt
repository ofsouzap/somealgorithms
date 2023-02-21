add_library (
	"graphs"
	"graphs.cpp"
	"list_graph.h" "list_graph.cpp"
)

target_link_libraries ("graphs" "mathutil" "data_structures")

add_subdirectory ("tests")