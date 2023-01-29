#include <algorithm>
#include <gtest/gtest.h>
#include "sorting.h"
#include "sorting_test_util.h"

using namespace sorting;

#define COUNTING_SORT_TEST(test_name, value_count, xs_csv)\
TEST(CountingSort, test_name)\
{\
	const int N = value_count;\
	int orig[N] = { xs_csv };\
	int min = *std::min_element(orig, orig + N);\
	int max = *std::max_element(orig, orig + N);\
	int* sorted = counting_sort(orig, N, min, max);\
	check_sorted_data(orig, sorted, N);\
}

COUNTING_SORT_TEST(SingleElement, 1, 4);
COUNTING_SORT_TEST(SortedNoDup, 6, 4 COMMA 6 COMMA 7 COMMA 9 COMMA 10 COMMA 13);
COUNTING_SORT_TEST(SortedDups, 8, 3 COMMA 3 COMMA 3 COMMA 4 COMMA 6 COMMA 7 COMMA 7 COMMA 9);
COUNTING_SORT_TEST(NoDups, 6, 5 COMMA 2 COMMA 8 COMMA -4 COMMA 7 COMMA 3)
COUNTING_SORT_TEST(Dups, 8, 5 COMMA 3 COMMA 8 COMMA -4 COMMA 7 COMMA 3 COMMA 8 COMMA 8)
COUNTING_SORT_TEST(General0, 13, -21 COMMA - 48 COMMA 50 COMMA 40 COMMA 17 COMMA - 5 COMMA - 31 COMMA 37 COMMA 19 COMMA 10 COMMA - 34 COMMA 12 COMMA 29)
COUNTING_SORT_TEST(General1, 6, -22 COMMA 41 COMMA - 17 COMMA - 15 COMMA - 47 COMMA 41)
COUNTING_SORT_TEST(General2, 13, -34 COMMA - 30 COMMA - 40 COMMA - 7 COMMA 49 COMMA 35 COMMA - 15 COMMA - 18 COMMA 10 COMMA - 36 COMMA - 19 COMMA - 25 COMMA 21)
COUNTING_SORT_TEST(General3, 17, 4 COMMA - 45 COMMA 48 COMMA 22 COMMA - 5 COMMA 16 COMMA 40 COMMA - 20 COMMA 14 COMMA 31 COMMA 43 COMMA - 28 COMMA 5 COMMA - 43 COMMA 4 COMMA - 38 COMMA - 27)
COUNTING_SORT_TEST(General4, 16, 14 COMMA 42 COMMA 23 COMMA 10 COMMA - 9 COMMA - 22 COMMA 49 COMMA - 24 COMMA 12 COMMA - 7 COMMA 2 COMMA 47 COMMA 23 COMMA 3 COMMA 28 COMMA 14)
