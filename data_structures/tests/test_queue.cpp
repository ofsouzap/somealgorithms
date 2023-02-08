#include <gtest/gtest.h>
#include "queue.h"


using namespace data_structures;

TEST(Queue, Init)
{
	Queue<int> q(5);
}

TEST(Queue, EnqueueNormal)
{
	Queue<int> q(10);
	q.enqueue(2);
	q.enqueue(6);
	q.enqueue(2);
	q.enqueue(5);
	q.enqueue(2);
}

TEST(Queue, EnqueueFull)
{
	Queue<int> q(3);
	q.enqueue(2);
	q.enqueue(6);
	q.enqueue(4);
	ASSERT_THROW(q.enqueue(6), QueueFullException);
}

TEST(Queue, DequeueFirst)
{
	Queue<int> q(4);
	q.enqueue(2);
	q.enqueue(6);
	q.enqueue(4);
	ASSERT_EQ(q.dequeue(), 2);
}

TEST(Queue, DequeueMid)
{
	Queue<int> q(4);
	q.enqueue(2);
	q.enqueue(6);
	q.enqueue(4);
	q.dequeue();
	ASSERT_EQ(q.dequeue(), 6);
}

TEST(Queue, DequeueEmpty)
{
	Queue<int> q(4);
	q.enqueue(2);
	q.enqueue(6);
	q.enqueue(3);
	q.dequeue();
	q.dequeue();
	q.dequeue();
	ASSERT_THROW(q.dequeue(), QueueEmptyException);
}

TEST(Queue, EnqueueCircular)
{
	Queue<int> q(5);
	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.dequeue();
	q.dequeue();
	q.enqueue(5);
}

TEST(Queue, DequeueCircular)
{
	Queue<int> q(5);
	q.enqueue(0);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.dequeue();
	q.dequeue();
	q.enqueue(5);
	ASSERT_EQ(q.dequeue(), 2);
}
