#pragma once

#include <cmath>
#include "mathutil.h"
#include "exceptions.h"

using mathutil::log2_ceil;

namespace data_structures
{

	template <class V_t, int N>
	class HeapPriorityQueue
	{

	private:

		typedef int K_t;

		struct Node
		{
			K_t priority;
			V_t value;
		};

		Node heap[N];
		/// <summary>
		/// Next index to insert a value in
		/// </summary>
		int end_i;

		static int iparent(int i)
		{
			return (i - 1) / 2;
		}

		static int ileft(int i)
		{
			return (2 * i) + 1;
		}

		static int iright(int i)
		{
			return (2 * i) + 2;
		}

		bool ivalid(int i) const
		{
			return i >= 0 && i < N;
		}

		bool iset(int i) const
		{
			return i < end_i && i >= 0;
		}

		bool ihasnode(int i) const
		{
			return ivalid(i) && iset(i);
		}

		bool is_full() const
		{

			return end_i == N;

		}

		void swap(int i1, int i2)
		{

			if (!ivalid(i1))
				throw HeapIndexOutOfRangeException();

			if (!ivalid(i2))
				throw HeapIndexOutOfRangeException();

			Node tmp = heap[i1];
			heap[i1] = heap[i2];
			heap[i2] = tmp;

		}

		void heapify(int root_i)
		{

			if (!ivalid(root_i))
				throw HeapIndexOutOfRangeException();

			if (!ihasnode(root_i))
				return;

			Node root = heap[root_i];
			K_t root_p = root.priority;

			int root_left_i = ileft(root_i);
			int root_right_i = iright(root_i);

			bool left_correct = !ihasnode(root_left_i) || heap[root_left_i].priority >= root_p;
			bool right_correct = !ihasnode(root_right_i) || heap[root_right_i].priority >= root_p;

			if (left_correct && right_correct)
			{
				return;
			}
			else if (!left_correct && !right_correct)
			{

				// As they are incorrect, we know that left and righ both have nodes in them

				Node root_left = heap[root_left_i];
				Node root_right = heap[root_right_i];

				if (root_left.priority > root_right.priority)
				{
					// Left child is bigger so put right child in root_i to locally fix heap
					swap(root_right_i, root_i);
					heapify(root_right_i);
				}
				else
				{
					// Right child is bigger so put left child in root_i to locally fix heap
					swap(root_left_i, root_i);
					heapify(root_left_i);
				}

			}
			else if (!left_correct)
			{

				// As left is incorrect, it must have a node in it

				swap(root_left_i, root_i);

				heapify(root_left_i);

			}
			else
			{

				// This is when !right_correct

				// As right is incorrect, it must have a node in it

				swap(root_right_i, root_i);

				heapify(root_right_i);

			}

		}

		void bottom_up_heapify()
		{

			// Meant to be run after inserting a new unsorted element at the bottom-layer of the heap
			// This will then restore the min-heap property to the heap

			for (int i = end_i / 2; i >= 0; i--)
			{

				// i will start at the index of the last node in the heap to have any children...
				//     ...and will go until the root of the node

				heapify(i);

			}

		}

		Node pop()
		{

			// Get root for output

			Node out = heap[0];

			// Swap last (heap[end_i-1]) element for root element...
			//     ..and decrease end index as the element has been removed

			swap(0, --end_i);

			// Fix the remaining heap
			
			heapify(0);

			// Return output

			return out;

		}

	public:

		HeapPriorityQueue()
		{

			end_i = 0;

		}

		void enqueue(K_t priority, V_t value)
		{

			if (is_full())
				throw HeapFullException();

			// Add new value

			heap[end_i++] = { priority, value };

			// Fix the heap

			bottom_up_heapify();

		}

		V_t dequeue()
		{

			Node n = pop();

			return n.value;

		}

	};

}
