#pragma once

#include <exception>
#include "mathutil.h"

using std::exception;
using mathutil::int_pow;

namespace sorting
{

	void array_swap(int* xs, int i1, int i2);

	void insertion_sort(int* xs, int N);

	void select_sort(int* xs, int N);

	int* merge_sort(int* xs, int N);

	void heapify(int* xs, int start, int N);
	void heap_sort(int* xs, int N);

	constexpr int COUNTING_SORT_MAX_RANGE = 256;
	class CountingSortRangeTooLargeException : public exception { };
	class CountingSortValueOutOfRangeException : public exception { };
	int* counting_sort(int* xs, int N, int min, int max);

	constexpr int RADIX_SORT_RADIX_BITS = 4;
	constexpr int RADIX_SORT_BIN_COUNT = int_pow(2, RADIX_SORT_RADIX_BITS);
	constexpr int RADIX_SORT_ITERATIONS = (sizeof(int) * 8) / RADIX_SORT_RADIX_BITS;
	class RadixSortNegativeValueException : public exception { };
	int extract_radix(int x, int n);
	void radix_sort(int* xs, int N);

}