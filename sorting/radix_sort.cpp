#include "sorting.h"
#include <vector>

using std::vector;

int sorting::extract_radix(int x, int n)
{

	// Create mask according to radix bit count

	int mask = 0b0;
	for (int i = 0; i < RADIX_SORT_RADIX_BITS; i++)
	{
		mask <<= 1;
		mask |= 0b1;
	}

	// Create shifted mask according to n

	int shifted_mask = mask << (n * RADIX_SORT_RADIX_BITS);

	// Apply shifted mask

	int masked = shifted_mask & x;

	// Shift value back

	masked >>= n * RADIX_SORT_RADIX_BITS;

	// Filter to only required bits (needed in case right-shifting caused 1s to be created from negative 2's compl. number)

	masked &= mask;

	// Return new value

	return masked;

}

void sorting::radix_sort(int* xs, int N)
{

	// Make sure values are positive
	for (int i = 0; i < N; i++) if (xs[i] < 0) throw new RadixSortNegativeValueException();

	// Create and initialize buffers

	vector<int>* curr = new vector<int>[RADIX_SORT_BIN_COUNT];
	vector<int>* next = new vector<int>[RADIX_SORT_BIN_COUNT];

	for (int i = 0; i < RADIX_SORT_BIN_COUNT; i++)
	{
		curr[i] = vector<int>();
		next[i] = vector<int>();
	}

	// Insert initial values into curr

	for (int i = 0; i < N; i++)
		curr[0].push_back(xs[i]);

	// Perform sorting iterations

	for (int rad_n = 0; rad_n < RADIX_SORT_ITERATIONS; rad_n++)
	{

		// ASSERT: curr is the buffer which holds the current items sorted by the current sorting

		// Do pass over curr to place items into next

		for (int buf_i = 0; buf_i < RADIX_SORT_BIN_COUNT; buf_i++)
		{

			for (int x : curr[buf_i])
			{

				int rad_val = extract_radix(x, rad_n);
				next[rad_val].push_back(x);

			}

			// Clear the used vector
			curr[buf_i].clear();

		}

		// ASSERT: all the vectors in curr are empty

		// Swap current and next buffers

		vector<int>* tmp = curr;
		curr = next;
		next = tmp;

	}

	// Read final ordering into array

	int out_i = 0;

	for (int buf_i = 0; buf_i < RADIX_SORT_BIN_COUNT; buf_i++)
		for (int x : curr[buf_i])
			xs[out_i++] = x;

}