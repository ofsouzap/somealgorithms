#include <gtest/gtest.h>
#include "tree_set.h"
#include <string>

using std::string;
using namespace data_structures;

TEST(TreeSet, Init)
{
	TreeSet set{};
}

TEST(TreeSet, Adding)
{

	TreeSet set{};

	set.add(0);
	set.add(1);
	set.add(2);
	set.add(3);
	set.add(4);
	set.add(5);
	set.add(6);
	set.add(7);
	set.add(8);

}

TEST(TreeSet, Replacing)
{

	TreeSet set{};

	set.add(0);
	set.add(1);
	set.add(2);
	set.add(0);
	set.add(4);
	set.add(4);
	set.add(4);
	set.add(3);
	set.add(2);

}

TEST(TreeSet, ContainsSingle)
{

	TreeSet set{};

	set.add(0);
	ASSERT_TRUE(set.contains(0));

}

TEST(TreeSet, ContainsAdded)
{

	TreeSet set{};

	set.add(0);
	set.add(1);
	set.add(2);
	set.add(3);
	set.add(4);
	set.add(5);
	set.add(6);
	set.add(7);
	set.add(8);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

}

TEST(TreeSet, ContainsReplaced)
{

	TreeSet set{};

	set.add(0);
	set.add(1);
	set.add(2);
	set.add(0);
	set.add(4);
	set.add(4);
	set.add(4);
	set.add(3);
	set.add(2);

	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(2));

}

TEST(TreeSet, ContainsNonExistantEmpty)
{

	TreeSet set{};

	ASSERT_FALSE(set.contains(0));

}

TEST(TreeSet, ContainsNonExistant)
{

	TreeSet set{};

	set.add(0);
	set.add(1);
	set.add(2);
	set.add(0);
	set.add(4);
	set.add(4);
	set.add(4);
	set.add(3);
	set.add(2);

	ASSERT_FALSE(set.contains(9));

}

TEST(TreeSet, RemoveStartFilled)
{

	TreeSet set{};

	set.add(5);
	set.add(8);
	set.add(0);
	set.add(2);
	set.add(7);
	set.add(1);
	set.add(4);
	set.add(3);
	set.add(6);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

	set.remove(5);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_FALSE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

}

TEST(TreeSet, RemoveStartOnlyElement)
{

	TreeSet set{};

	set.add(0);

	ASSERT_TRUE(set.contains(0));

	set.remove(0);

	ASSERT_FALSE(set.contains(0));

}

TEST(TreeSet, RemoveLeaf)
{

	TreeSet set{};

	set.add(5);
	set.add(8);
	set.add(0);
	set.add(2);
	set.add(7);
	set.add(1);
	set.add(4);
	set.add(3);
	set.add(6);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

	set.remove(3);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_FALSE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

}

TEST(TreeSet, RemoveInside)
{

	TreeSet set{};

	set.add(5);
	set.add(8);
	set.add(0);
	set.add(2);
	set.add(7);
	set.add(1);
	set.add(4);
	set.add(3);
	set.add(6);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

	set.remove(2);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_FALSE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

}

TEST(TreeSet, RemoveEnd)
{

	TreeSet set{};

	set.add(5);
	set.add(8);
	set.add(0);
	set.add(2);
	set.add(7);
	set.add(1);
	set.add(4);
	set.add(3);
	set.add(6);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

	set.remove(8);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_FALSE(set.contains(8));

}

TEST(TreeSet, RemoveNonExistant)
{

	TreeSet set{};

	set.add(5);
	set.add(8);
	set.add(0);
	set.add(2);
	set.add(7);
	set.add(1);
	set.add(4);
	set.add(3);
	set.add(6);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

	ASSERT_THROW(set.remove(20), KeyDoesntExistException);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

}

TEST(TreeSet, RemoveNoSuccessorRoot)
{

	TreeSet set{};

	set.add(8);
	set.add(0);
	set.add(1);
	set.add(2);
	set.add(3);
	set.add(4);
	set.add(5);
	set.add(6);
	set.add(7);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

	set.remove(8);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_FALSE(set.contains(8));

}

TEST(TreeSet, RemoveNoSuccessorInside)
{

	TreeSet set{};

	set.add(5);
	set.add(8);
	set.add(0);
	set.add(2);
	set.add(7);
	set.add(1);
	set.add(4);
	set.add(3);
	set.add(6);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_TRUE(set.contains(8));

	set.remove(8);

	ASSERT_TRUE(set.contains(0));
	ASSERT_TRUE(set.contains(1));
	ASSERT_TRUE(set.contains(2));
	ASSERT_TRUE(set.contains(3));
	ASSERT_TRUE(set.contains(4));
	ASSERT_TRUE(set.contains(5));
	ASSERT_TRUE(set.contains(6));
	ASSERT_TRUE(set.contains(7));
	ASSERT_FALSE(set.contains(8));

}
