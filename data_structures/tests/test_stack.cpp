#include <gtest/gtest.h>
#include "stack.h"


using namespace data_structures;

TEST(Stack, Init)
{
	Stack<int> s(5);
}

TEST(Stack, PushNormal)
{
	Stack<int> s(10);
	s.push(2);
	s.push(6);
	s.push(2);
	s.push(5);
	s.push(2);
}

TEST(Stack, PushFull)
{
	Stack<int> s(3);
	s.push(2);
	s.push(6);
	s.push(4);
	ASSERT_THROW(s.push(6), StackFullException);
}

TEST(Stack, PopTop)
{
	Stack<int> s(4);
	s.push(2);
	s.push(6);
	s.push(4);
	ASSERT_EQ(s.pop(), 4);
}

TEST(Stack, PopMid)
{
	Stack<int> s(4);
	s.push(2);
	s.push(6);
	s.push(4);
	s.pop();
	ASSERT_EQ(s.pop(), 6);
}

TEST(Stack, PopEmpty)
{
	Stack<int> s(4);
	s.push(2);
	s.push(6);
	s.push(3);
	s.pop();
	s.pop();
	s.pop();
	ASSERT_THROW(s.pop(), StackEmptyException);
}
