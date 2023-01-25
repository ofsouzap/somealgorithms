#include <gtest/gtest.h>
#include "sorting.h"
#include "sorting_test_util.h"

using namespace sorting;

TEST(SelectSort, SingleElement)
{

	const int N = 1;
	int data[N] = { 2 };
	test_sorting_list_inplace(data, N, select_sort);

}

TEST(SelectSort, AlreadyOrdered)
{

	const int N = 5;
	int data[N] = { 2, 6, 8, 10, 36 };
	test_sorting_list_inplace(data, N, select_sort);

}

TEST(SelectSort, Normal)
{

	const int N = 7;
	int data[N] = { 7, 24, 6, 23, -3, 9, -23 };
	test_sorting_list_inplace(data, N, select_sort);

}

TEST(SelectSort, NormalDuplicates)
{

	const int N = 9;
	int data[N] = { 2, 6, -8, 7, 36, -2, 2, -8, 7 };
	test_sorting_list_inplace(data, N, select_sort);

}