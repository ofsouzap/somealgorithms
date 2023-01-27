#pragma once

namespace sorting
{

	void array_swap(int* xs, int i1, int i2);

	void insertion_sort(int* xs, int N);

	void select_sort(int* xs, int N);

	int* merge_sort(int* xs, int N);

	void heapify(int* xs, int start, int N);
	void heap_sort(int* xs, int N);

}