#pragma once


void check_ordering(int* data, int N)
{

	// If less than 2 elements then they must be sorted
	if (N < 2)
		return;

	// Otherwise, check the elements in order

	int prev = data[0];

	for (int i = 1; i < N; i++)
	{
		ASSERT_LE(prev, data[i]);
		prev = data[i];
	}

}

void check_contents(int* a, int* b, int N)
{

	bool* used = new bool[N];
	for (int i = 0; i < N; i++) used[i] = false;

	for (int i = 0; i < N; i++)
	{

		// Check that a occurs in b another time
		
		int ele = a[i];

		bool found = false;

		for (int j = 0; j < N; j++)
		{

			if (used[j]) continue;

			if (b[j] == ele)
			{
				used[j] = true;
				found = true;
				break;
			}

		}

		ASSERT_TRUE(found);

	}

	delete[] used;

}

void test_sorting_list_inplace(int* data, int N, void (*sorter)(int*, int))
{

	// Make copy of original data

	int* orig_copy = new int[N];
	std::copy(data, data + N, orig_copy);

	// Perform sort

	sorter(data, N);

	// Check order

	check_ordering(data, N);

	// Check contents

	check_contents(data, orig_copy, N);

}

void test_sorting_list_oncopy(int* data, int N, int* (*sorter)(int*, int))
{

	// Perform sort

	int* sorted = sorter(data, N);

	// Check order

	check_ordering(sorted, N);

	// Check contents

	check_contents(sorted, data, N);

}
