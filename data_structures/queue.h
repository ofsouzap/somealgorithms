#pragma once

#include <exception>

using std::exception;

namespace data_structures
{

	class QueueEmptyException : public exception { };
	class QueueFullException : public exception { };

	template <class T>
	/// <summary>
	/// Implementation of fixed-maximum-size circular queue for data of generic type
	/// </summary>
	class Queue
	{

	private:

		int size;
		T* data;

		/// <summary>
		/// The next element to remove or negative if the queue is empty
		/// </summary>
		int head;

		/// <summary>
		/// The next empty space to use
		/// </summary>
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

		void enqueue(T value) const
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