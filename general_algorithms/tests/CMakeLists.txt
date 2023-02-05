add_executable ("test_lcs" "test_lcs.cpp")
target_link_libraries ("test_lcs" "gtest_main" "general_algorithms")
add_test (
	NAME "test_lcs"
	COMMAND "test_lcs"
)