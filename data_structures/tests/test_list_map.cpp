#include <gtest/gtest.h>
#include "list_map.h"
#include <string>

using std::string;
using namespace data_structures;

TEST(ListMap, Init)
{
	ListMap<int, string> map{};
}

TEST(ListMap, Adding)
{

	ListMap<int, string> map{};

	map.set(0, "zero");
	map.set(1, "one");
	map.set(2, "two");
	map.set(3, "three");
	map.set(4, "four");
	map.set(5, "five");
	map.set(6, "six");
	map.set(7, "seven");
	map.set(8, "eight");

}

TEST(ListMap, Replacing)
{

	ListMap<int, string> map{};

	map.set(0, "zero");
	map.set(1, "one");
	map.set(2, "two");
	map.set(0, "zerox2");
	map.set(4, "fourjustfour");
	map.set(4, "fourthesecond");
	map.set(4, "fourthethird");
	map.set(3, "three");
	map.set(2, "twoagain");

}

TEST(ListMap, GettingSingle)
{

	ListMap<int, string> map{};

	map.set(0, "zero");
	ASSERT_EQ(map.get(0), "zero");

}

TEST(ListMap, GettingAdded)
{

	ListMap<int, string> map{};

	map.set(0, "zero");
	map.set(1, "one");
	map.set(2, "two");
	map.set(3, "three");
	map.set(4, "four");
	map.set(5, "five");
	map.set(6, "six");
	map.set(7, "seven");
	map.set(8, "eight");

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

}

TEST(ListMap, GettingReplaced)
{

	ListMap<int, string> map{};

	map.set(0, "zero");
	map.set(1, "one");
	map.set(2, "two");
	map.set(0, "zerox2");
	map.set(4, "fourjustfour");
	map.set(4, "fourthesecond");
	map.set(4, "fourthethird");
	map.set(3, "three");
	map.set(2, "twoagain");

	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(0), "zerox2");
	ASSERT_EQ(map.get(4), "fourthethird");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(2), "twoagain");

}

TEST(ListMap, GettingNonExistantEmpty)
{

	ListMap<int, string> map{};

	ASSERT_THROW(map.get(0), KeyDoesntExistException);

}

TEST(ListMap, GettingNonExistant)
{

	ListMap<int, string> map{};

	map.set(0, "zero");
	map.set(1, "one");
	map.set(2, "two");
	map.set(0, "zerox2");
	map.set(4, "fourjustfour");
	map.set(4, "fourthesecond");
	map.set(4, "fourthethird");
	map.set(3, "three");
	map.set(2, "twoagain");

	ASSERT_THROW(map.get(9), KeyDoesntExistException);

}
