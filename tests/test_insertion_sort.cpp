#include <gtest/gtest.h>
#include "sorting.h"
#include "sorting_test_util.h"

using namespace sorting;

constexpr inplace_sorting_function_t sort_function = insertion_sort;
constexpr inplace_testing_function_t test_function = test_sorting_list_inplace;
#define TEST_SUITE_NAME InsertionSort

BASIC_SORTING_TEST(TEST_SUITE_NAME, SingleElement, 1, 1)
BASIC_SORTING_TEST(TEST_SUITE_NAME, AlreadyOrdered, 5, 2 COMMA 6 COMMA 8 COMMA 10 COMMA 36)
BASIC_SORTING_TEST(TEST_SUITE_NAME, Normal, 7, 7 COMMA 24 COMMA 6 COMMA 23 COMMA -3 COMMA 9 COMMA -23)
BASIC_SORTING_TEST(TEST_SUITE_NAME, NormalDuplicates, 9, 2 COMMA 6 COMMA -8 COMMA 7 COMMA 36 COMMA -2 COMMA 2 COMMA -8 COMMA 7)

#undef TEST_SUITE_NAME
