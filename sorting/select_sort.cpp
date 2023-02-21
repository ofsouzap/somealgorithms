#include "sorting.h"

/// @brief Sorts an array of elements in-place using the select sort algorithm.
/// PRECONDITION: xs points to the first element of a contiguous array with N elements.
/// POSTCONDITION: xs will point to the first element of the now-sorted array with the exact same elements but probably reordered.
void sorting::select_sort(int* xs, int N)
{

	for (int i = 0; i < N - 1; i++) // N.B. "N-1" because don't need to check the last element
	{
		
		// ASSERT: elements from xs[0] (inclusive) to xs[i] (exclusive) are sorted

		int min_j = i;
		int min_v = xs[min_j];

		for (int j = i; j < N; j++)
		{

			// Find smallest element in xs[i:N]

			int v = xs[j];

			if (v < min_v)
			{
				min_v = v;
				min_j = j;
			}

		}

		// Swap the smallest element into xs[i]

		array_swap(xs, i, min_j);

	}

}