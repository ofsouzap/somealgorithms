#include "sorting.h"

/// @brief Sorts an array of elements using the merge sort algorithm. A sorted *copy* of the array is returned.
/// PRECONDITION: xs points to the first element of a contiguous array with N elements.
/// POSTCONDITION: the returned pointer will point to the first element of the now-sorted array with the exact same elements but probably reordered.
int* sorting::merge_sort(int* xs, int N)
{

	if (N == 0)
	{
		return nullptr;
	}
	else if (N == 1)
	{
		int* out = new int[1] { *xs };
		return out;
	}
	else
	{

		// Split

		int split = N / 2;

		int* lefts = xs;
		int lefts_N = split;

		int* rights = xs + lefts_N;
		int rights_N = N - lefts_N;

		// Recurse

		int* lefts_sorted = merge_sort(lefts, lefts_N);
		int* rights_sorted = merge_sort(rights, rights_N);

		// Merge

		// ASSERT: the arrays pointed to by lefts_sorted and rights_sorted are sorted with lengths lefts_N and rights_N respectively

		int* sorteds = new int[N];
		int sorteds_i = 0;

		int l_i = 0, r_i = 0;

		while (l_i < lefts_N && r_i < rights_N)
		{

			// ASSERT: all the elements in lefts_sorted[0:l_i] and rights_sorted[0:r_i] have been placed into the array sorteds

			int l_v = lefts_sorted[l_i];
			int r_v = rights_sorted[r_i];

			if (l_v < r_v)
			{
				sorteds[sorteds_i++] = l_v;
				l_i++;
			}
			else
			{
				sorteds[sorteds_i++] = r_v;
				r_i++;
			}

		}

		if (l_i < lefts_N)
		{

			// Add all remaining elements of lefts_sorted

			// ASSERT: r_i == rights_N
			// ASSERT: all the elements of rights_sorted have been added to sorteds

			for (; l_i < lefts_N; l_i++)
				sorteds[sorteds_i++] = lefts_sorted[l_i];

		}
		else if (r_i < rights_N)
		{

			// Add all remaining elements of rights_sorted

			// ASSERT: l_i == lefts_N
			// ASSERT: all the elements of lefts_sorted have been added to sorteds

			for (; r_i < rights_N; r_i++)
				sorteds[sorteds_i++] = rights_sorted[r_i];

		}

		// Clean up

		delete[] lefts_sorted, rights_sorted;

		// Return output

		return sorteds;

	}

}