#include "sorting.h"

int* sorting::counting_sort(int* xs, int N, int min, int max)
{

	// Check input value range

	int range = max - min + 1;
	if (range > COUNTING_SORT_MAX_RANGE)
		throw new CountingSortRangeTooLargeException();

	// Count values

	int* counts = new int[range];

	for (int i = 0; i < range; i++) counts[i] = 0; // Initialize array values

	for (int i = 0; i < N; i++)
	{

		int x = xs[i];

		if (x < min || x > max)
			throw new CountingSortValueOutOfRangeException();

		int x_pos = x - min;

		// ASSERT: 0 <= x_pos < range

		counts[x_pos]++;

	}

	// ASSERT: the total of the values in counts is N

	// Put counted items into output array

	int* outs = new int[N];

	int counts_i = 0;

	for (int outs_i = 0; outs_i < N; outs_i++)
	{

		// Move to next available
		while(counts[counts_i] == 0)
			counts_i++;

		outs[outs_i] = min + counts_i; // Add the next value

		counts[counts_i]--; // Reduce counts remaining of this value

	}

	// ASSERT: all the values in counts are 0

	// Clean up

	delete[] counts;

	// Return output

	return outs;

}