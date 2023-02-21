#include "sorting.h"
#include <utility>

bool heap_index_valid(int i, int N)
{
	return i >= 0 && i < N;
}

std::pair<int, int> heap_children(int i)
{
	return std::pair<int, int>(2 * i + 1, 2 * i + 2);
}

int heap_parent(int i)
{
	return (i - 1) / 2;
}

/// @brief Make it such that, in the heap with root node xs, the subtree with root node start satisfies the max-heap property.
/// PRECONDITION: xs points to the first element of a contiguous array with N elements and the child subtrees are valid max-heaps.
/// POSTCONDITION: the subtree with root node start will satify the max-heap property.
void sorting::heapify(int* xs, int start, int N)
{

	int curr = start;

	while (true)
	{

		int curr_v = xs[curr];

		auto children_indexes = heap_children(curr);
		int left = children_indexes.first;
		int right = children_indexes.second;

		bool left_exists = heap_index_valid(left, N);
		bool right_exists = heap_index_valid(right, N);

		bool left_correct = !left_exists || xs[left] <= curr_v;
		bool right_correct = !right_exists || xs[right] <= curr_v;

		if (left_correct && right_correct)
		{
			// We are done
			break;
		}
		else if (!left_correct && !right_correct)
		{
			if (xs[left] > xs[right])
			{
				array_swap(xs, curr, left);
				curr = left;
			}
			else
			{
				array_swap(xs, curr, right);
				curr = right;
			}
		}
		else if (!left_correct)
		{
			array_swap(xs, curr, left);
			curr = left;
		}
		else if (!right_correct)
		{
			array_swap(xs, curr, right);
			curr = right;
		}

	}

}

/// @brief Sorts an array of elements in-place using the heap sort algorithm.
/// PRECONDITION: xs points to the first element of a contiguous array with N elements.
/// POSTCONDITION: xs will point to the first element of the now-sorted array with the exact same elements but probably reordered.
void sorting::heap_sort(int* xs, int N)
{

	// Arrange the elements of xs into a max-heap

	for (int i = N - 1; i >= 0; i--)
	{

		// ASSERT: All the subtrees with roots at nodes with indexes from N-1 (inclusive) to i (exclusive) fulfill the max-heap property

		heapify(xs, i, N);

	}

	// Use the created heap to sort the elements into an array

	// ASSERT: the N elements of xs are arranged in the form of a max-heap (the first element is the largest)

	for (int i = 0; i < N; i++)
	{

		// ASSERT: the elements in xs[N-i:N] are in their correct, sorted positions

		// Take the root element of the max-heap and put it in the sorted array section

		array_swap(xs, 0, N - i - 1);

		// Correct the current heap

		heapify(xs, 0, N - i - 1);

	}

}