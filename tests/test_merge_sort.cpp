#include <gtest/gtest.h>
#include "sorting.h"
#include "sorting_test_util.h"

using namespace sorting;

TEST(MergeSort, SingleElement)
{

	const int N = 1;
	int data[N] = { 2 };
	test_sorting_list_oncopy(data, N, merge_sort);

}

TEST(MergeSort, AlreadyOrdered)
{

	const int N = 5;
	int data[N] = { 2, 6, 8, 10, 36 };
	test_sorting_list_oncopy(data, N, merge_sort);

}

TEST(MergeSort, Normal)
{

	const int N = 7;
	int data[N] = { 7, 24, 6, 23, -3, 9, -23 };
	test_sorting_list_oncopy(data, N, merge_sort);

}

TEST(MergeSort, NormalDuplicates)
{

	const int N = 9;
	int data[N] = { 2, 6, -8, 7, 36, -2, 2, -8, 7 };
	test_sorting_list_oncopy(data, N, merge_sort);

}