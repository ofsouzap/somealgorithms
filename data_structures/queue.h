#pragma once

#include "exceptions.h"

namespace data_structures
{

	/// @brief Implementation of fixed-maximum-size circular queue for data of generic type
	/// @tparam T The type of the data in the queue
	template <class T>
	class Queue
	{

	private:

		int size;
		T* data;

		/// @brief The next element to remove or negative if the queue is empty
		int head;

		/// @brief The next empty space to use
		int tail;

		void head_forward()
		{
			head++;
			head %= size;
		}

		void tail_forward()
		{
			tail++;
			tail %= size;
		}

	public:

		Queue(int size)
		{
			this->size = size;
			data = new T[size];
			head = -1;
			tail = 0;
		}

		bool is_empty() const
		{
			return head < 0;
		}

		bool is_full() const
		{
			return head == tail;
		}

		int get_count() const
		{
			if (head < 0)
				return 0;
			else if (head >= tail)
				return tail - head;
			else
				return size - head + 1 + tail;
		}

		void enqueue(T value)
		{

			if (is_full())
				throw QueueFullException();
			else
			{

				data[tail] = value;

				// If was empty then is not empty any more
				if (head < 0)
					head = tail;

				tail_forward();

			}

		}

		T dequeue()
		{

			if (is_empty())
				throw QueueEmptyException();
			else
			{
				T out = data[head];
				head_forward();

				// If, after moving forward, the head is at the tail then the queue has just been emptied
				if (head == tail)
					head = -1;

				return out;
			}

		}

	};

}