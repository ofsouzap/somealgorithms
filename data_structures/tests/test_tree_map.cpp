#include <gtest/gtest.h>
#include "tree_map.h"
#include <string>

using std::string;
using namespace data_structures;

TEST(TreeMap, Init)
{
	TreeMap<string> map{};
}

TEST(TreeMap, Adding)
{

	TreeMap<string> map{};

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

TEST(TreeMap, Replacing)
{

	TreeMap<string> map{};

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

TEST(TreeMap, GettingSingle)
{

	TreeMap<string> map{};

	map.set(0, "zero");
	ASSERT_EQ(map.get(0), "zero");

}

TEST(TreeMap, GettingAdded)
{

	TreeMap<string> map{};

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

TEST(TreeMap, GettingReplaced)
{

	TreeMap<string> map{};

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

TEST(TreeMap, GettingNonExistantEmpty)
{

	TreeMap<string> map{};

	ASSERT_THROW(map.get(0), KeyDoesntExistException);

}

TEST(TreeMap, GettingNonExistant)
{

	TreeMap<string> map{};

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

TEST(TreeMap, DeleteStartFilled)
{

	TreeMap<string> map{};

	map.set(5, "five");
	map.set(8, "eight");
	map.set(0, "zero");
	map.set(2, "two");
	map.set(7, "seven");
	map.set(1, "one");
	map.set(4, "four");
	map.set(3, "three");
	map.set(6, "six");

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

	map.remove(5);

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_THROW(map.get(5), KeyDoesntExistException);
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

}

TEST(TreeMap, DeleteStartOnlyElement)
{

	TreeMap<string> map{};

	map.set(0, "zero");

	ASSERT_EQ(map.get(0), "zero");

	map.remove(0);

	ASSERT_THROW(map.get(0), KeyDoesntExistException);

}

TEST(TreeMap, DeleteLeaf)
{

	TreeMap<string> map{};

	map.set(5, "five");
	map.set(8, "eight");
	map.set(0, "zero");
	map.set(2, "two");
	map.set(7, "seven");
	map.set(1, "one");
	map.set(4, "four");
	map.set(3, "three");
	map.set(6, "six");

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

	map.remove(3);

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_THROW(map.get(3), KeyDoesntExistException);
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

}

TEST(TreeMap, DeleteInside)
{

	TreeMap<string> map{};

	map.set(5, "five");
	map.set(8, "eight");
	map.set(0, "zero");
	map.set(2, "two");
	map.set(7, "seven");
	map.set(1, "one");
	map.set(4, "four");
	map.set(3, "three");
	map.set(6, "six");

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

	map.remove(2);

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_THROW(map.get(2), KeyDoesntExistException);
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

}

TEST(TreeMap, DeleteEnd)
{

	TreeMap<string> map{};

	map.set(5, "five");
	map.set(8, "eight");
	map.set(0, "zero");
	map.set(2, "two");
	map.set(7, "seven");
	map.set(1, "one");
	map.set(4, "four");
	map.set(3, "three");
	map.set(6, "six");

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

	map.remove(8);

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_THROW(map.get(8), KeyDoesntExistException);

}

TEST(TreeMap, DeleteNonExistant)
{

	TreeMap<string> map{};

	map.set(5, "five");
	map.set(8, "eight");
	map.set(0, "zero");
	map.set(2, "two");
	map.set(7, "seven");
	map.set(1, "one");
	map.set(4, "four");
	map.set(3, "three");
	map.set(6, "six");

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

	ASSERT_THROW(map.remove(20), KeyDoesntExistException);

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

TEST(TreeMap, DeleteNoSuccessorRoot)
{

	TreeMap<string> map{};

	map.set(8, "eight");
	map.set(0, "zero");
	map.set(1, "one");
	map.set(2, "two");
	map.set(3, "three");
	map.set(4, "four");
	map.set(5, "five");
	map.set(6, "six");
	map.set(7, "seven");

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

	map.remove(8);

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_THROW(map.get(8), KeyDoesntExistException);

}

TEST(TreeMap, DeleteNoSuccessorInside)
{

	TreeMap<string> map{};

	map.set(5, "five");
	map.set(8, "eight");
	map.set(0, "zero");
	map.set(2, "two");
	map.set(7, "seven");
	map.set(1, "one");
	map.set(4, "four");
	map.set(3, "three");
	map.set(6, "six");

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_EQ(map.get(8), "eight");

	map.remove(8);

	ASSERT_EQ(map.get(0), "zero");
	ASSERT_EQ(map.get(1), "one");
	ASSERT_EQ(map.get(2), "two");
	ASSERT_EQ(map.get(3), "three");
	ASSERT_EQ(map.get(4), "four");
	ASSERT_EQ(map.get(5), "five");
	ASSERT_EQ(map.get(6), "six");
	ASSERT_EQ(map.get(7), "seven");
	ASSERT_THROW(map.get(8), KeyDoesntExistException);

}
