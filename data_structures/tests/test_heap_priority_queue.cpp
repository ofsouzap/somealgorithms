#include <gtest/gtest.h>
#include "heap_priority_queue.h"
#include <string>

using std::string;
using namespace data_structures;

TEST(HeapPriorityQueue, Init)
{
	HeapPriorityQueue<string> q(5);
}

TEST(HeapPriorityQueue, EnqueueSmall)
{

	HeapPriorityQueue<string> q(5);

	q.enqueue( 0, "task a" );
	q.enqueue( 1, "task d" );
	q.enqueue( 2, "task c" );
	q.enqueue( 3, "task d" );

}

TEST(HeapPriorityQueue, EnqueueLarge)
{

	HeapPriorityQueue<string> q(200);

	for (int i = 0; i < 100; i++)
	{
		q.enqueue( 0, "task" );
	}

}

TEST(HeapPriorityQueue, EnqueueFillExactly)
{

	HeapPriorityQueue<string> q(100);

	for (int i = 0; i < 100; i++)
	{
		q.enqueue(0, "task");
	}

}

TEST(HeapPriorityQueue, EnqueueOverfill)
{

	HeapPriorityQueue<string> q(100);

	for (int i = 0; i < 100; i++)
	{
		q.enqueue(0, "task");
	}

	ASSERT_THROW(q.enqueue(0, "task"), HeapFullException);

}

TEST(HeapPriorityQueue, EnqueueDequeueOverfill)
{

	HeapPriorityQueue<string> q(100);

	/* +20 */ for (int i = 0; i < 20; i++) q.enqueue(0, "task");
	/* -10 */ for (int i = 0; i < 10; i++) q.dequeue();
	/* +80 */ for (int i = 0; i < 80; i++) q.enqueue(0, "task");
	/* -20 */ for (int i = 0; i < 20; i++) q.dequeue();
	/* +30 */ for (int i = 0; i < 30; i++) q.enqueue(0, "task");

	ASSERT_THROW(q.enqueue(0, "task"), HeapFullException);

}

TEST(HeapPriorityQueue, DequeueAllSame)
{

	HeapPriorityQueue<string> q(200);

	for (int i = 0; i < 100; i++)
	{
		q.enqueue(0, "task");
	}

	for (int i = 0; i < 100; i++)
	{
		string out = q.dequeue();
		ASSERT_EQ(out, "task");
	}

}

TEST(HeapPriorityQueue, DequeueAlreadyOrdered)
{

	HeapPriorityQueue<int> q(200);

	for (int i = 0; i < 100; i++)
	{
		q.enqueue(i, i);
	}

	for (int i = 0; i < 100; i++)
	{
		int out = q.dequeue();
		ASSERT_EQ(out, i);
	}

}

TEST(HeapPriorityQueue, DequeueReverseOrdered)
{

	HeapPriorityQueue<int> q(200);

	for (int i = 99; i >= 0; i--)
	{
		q.enqueue(i, i);
	}

	for (int i = 0; i < 100; i++)
	{
		int out = q.dequeue();
		ASSERT_EQ(out, i);
	}

}

TEST(HeapPriorityQueue, DequeueAnyOrder)
{

	HeapPriorityQueue<int> q(50);

	q.enqueue(4, 4);
	q.enqueue(7, 7);
	q.enqueue(2, 2);
	q.enqueue(5, 5);
	q.enqueue(2, 2);
	q.enqueue(9, 9);
	q.enqueue(4, 4);
	q.enqueue(0, 0);

	ASSERT_EQ(q.dequeue(), 0);
	ASSERT_EQ(q.dequeue(), 2);
	ASSERT_EQ(q.dequeue(), 2);
	ASSERT_EQ(q.dequeue(), 4);
	ASSERT_EQ(q.dequeue(), 4);
	ASSERT_EQ(q.dequeue(), 5);
	ASSERT_EQ(q.dequeue(), 7);
	ASSERT_EQ(q.dequeue(), 9);

}
