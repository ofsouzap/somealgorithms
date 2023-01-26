#include <gtest/gtest.h>
#include "sorting.h"
#include "sorting_test_util.h"

using namespace sorting;

constexpr inplace_sorting_function_t sort_function = select_sort;
constexpr inplace_testing_function_t test_function = test_sorting_list_inplace;
#define TEST_SUITE_NAME SelectSort

BASIC_SORTING_TEST(TEST_SUITE_NAME, SingleElement, 1, 1)
BASIC_SORTING_TEST(TEST_SUITE_NAME, AlreadyOrdered, 5, 2 COMMA 6 COMMA 8 COMMA 10 COMMA 36)
BASIC_SORTING_TEST(TEST_SUITE_NAME, Normal, 7, 7 COMMA 24 COMMA 6 COMMA 23 COMMA - 3 COMMA 9 COMMA - 23)
BASIC_SORTING_TEST(TEST_SUITE_NAME, NormalDuplicates, 9, 2 COMMA 6 COMMA - 8 COMMA 7 COMMA 36 COMMA - 2 COMMA 2 COMMA - 8 COMMA 7)
BASIC_SORTING_TEST(TEST_SUITE_NAME, General0, 13, -21 COMMA - 48 COMMA 50 COMMA 40 COMMA 17 COMMA - 5 COMMA - 31 COMMA 37 COMMA 19 COMMA 10 COMMA - 34 COMMA 12 COMMA 29)
BASIC_SORTING_TEST(TEST_SUITE_NAME, General1, 6, -22 COMMA 41 COMMA - 17 COMMA - 15 COMMA - 47 COMMA 41)
BASIC_SORTING_TEST(TEST_SUITE_NAME, General2, 13, -34 COMMA - 30 COMMA - 40 COMMA - 7 COMMA 49 COMMA 35 COMMA - 15 COMMA - 18 COMMA 10 COMMA - 36 COMMA - 19 COMMA - 25 COMMA 21)
BASIC_SORTING_TEST(TEST_SUITE_NAME, General3, 17, 4 COMMA - 45 COMMA 48 COMMA 22 COMMA - 5 COMMA 16 COMMA 40 COMMA - 20 COMMA 14 COMMA 31 COMMA 43 COMMA - 28 COMMA 5 COMMA - 43 COMMA 4 COMMA - 38 COMMA - 27)
BASIC_SORTING_TEST(TEST_SUITE_NAME, General4, 16, 14 COMMA 42 COMMA 23 COMMA 10 COMMA - 9 COMMA - 22 COMMA 49 COMMA - 24 COMMA 12 COMMA - 7 COMMA 2 COMMA 47 COMMA 23 COMMA 3 COMMA 28 COMMA 14)

#undef TEST_SUITE_NAME
