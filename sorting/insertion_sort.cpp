#include "sorting.h"

/// @brief Sorts an array of elements in-place using the insertion sort algorithm.
/// PRECONDITION: xs points to the first element of a contiguous array with N elements.
/// POSTCONDITION: xs will point to the first element of the now-sorted array with the exact same elements but probably reordered.
void sorting::insertion_sort(int* xs, int N)
{
	
	for (int i = 1; i < N; i++)
	{

		// ASSERT: The elements from xs[0] (inclusive) to xs[i] (exclusive) are sorted already

		// Bubble it down until it is in the correct position
		for (int j = i; j > 0; j--)
		{

			if (xs[j] < xs[j-1])
			{

				array_swap(xs, j, j - 1);

			}

		}

	}

}