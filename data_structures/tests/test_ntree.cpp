#include <gtest/gtest.h>
#include "ntree.h"

using namespace data_structures;

TEST(NTree, Init)
{
    NTreeNode<2, int> n0(0);
    NTreeNode<6, int> n1(6);
    NTreeNode<3, bool> n2(false);
    NTreeNode<2, char> n3('A');
    NTreeNode<3, NTreeNode<3, bool>> n4(n2);
}

TEST(NTree, SetChild0)
{

    NTreeNode<2, int> tree(0);

    tree.set_child(0, 1);
    tree.set_child(1, 2);

    ASSERT_EQ(tree.get_child(0)->get_value(), 1);
    ASSERT_EQ(tree.get_child(1)->get_value(), 2);

}

TEST(NTree, SetChild1)
{

    NTreeNode<3, int> tree(0);

    tree.set_child(0, 1);
    tree.set_child(2, 2);

    ASSERT_EQ(tree.get_child(0)->get_value(), 1);
    ASSERT_EQ(tree.get_child(2)->get_value(), 2);

}

TEST(NTree, SetChild2)
{

    NTreeNode<5, bool> tree(true);

    tree.set_child(0, false);
    tree.set_child(1, false);
    tree.set_child(2, true);
    tree.set_child(3, true);
    tree.get_child(1)->set_child(3, true);

    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(tree.get_child(0)->get_child(i), nullptr);
        ASSERT_EQ(tree.get_child(2)->get_child(i), nullptr);
        ASSERT_EQ(tree.get_child(3)->get_child(i), nullptr);
    }

    ASSERT_EQ(tree.get_child(1)->get_child(0), nullptr);
    ASSERT_EQ(tree.get_child(1)->get_child(1), nullptr);
    ASSERT_EQ(tree.get_child(1)->get_child(2), nullptr);
    ASSERT_EQ(tree.get_child(1)->get_child(4), nullptr);

    ASSERT_EQ(tree.get_child(1)->get_child(3)->get_value(), true);

}
