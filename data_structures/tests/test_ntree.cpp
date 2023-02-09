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
    NTreeNode<2, int> child0(1);
    NTreeNode<2, int> child1(2);

    tree.set_child(0, &child0);
    tree.set_child(1, &child1);

    ASSERT_EQ(tree.get_child(0)->get_value(), 1);
    ASSERT_EQ(tree.get_child(1)->get_value(), 2);

}

TEST(NTree, SetChild1)
{

    NTreeNode<3, int> tree(0);
    NTreeNode<3, int> child0(1);
    NTreeNode<3, int> child1(2);

    tree.set_child(0, &child0);
    tree.set_child(2, &child1);

    ASSERT_EQ(tree.get_child(0)->get_value(), 1);
    ASSERT_EQ(tree.get_child(2)->get_value(), 2);

}

TEST(NTree, SetChild2)
{

    NTreeNode<5, bool> tree(true);
    NTreeNode<5, bool> child0(false);
    NTreeNode<5, bool> child1(false);
    NTreeNode<5, bool> child2(true);
    NTreeNode<5, bool> child3(true);

    tree.set_child(0, &child0);
    tree.set_child(1, &child1);
    tree.set_child(2, &child2);
    child0.set_child(3, &child3);

    for (int i = 0; i < 5; i++)
    {
        ASSERT_EQ(child1.get_child(i), nullptr);
        ASSERT_EQ(child2.get_child(i), nullptr);
        ASSERT_EQ(child3.get_child(i), nullptr);
    }

    ASSERT_EQ(child0.get_child(0), nullptr);
    ASSERT_EQ(child0.get_child(1), nullptr);
    ASSERT_EQ(child0.get_child(2), nullptr);
    ASSERT_EQ(child0.get_child(4), nullptr);

    ASSERT_EQ(tree.get_child(0)->get_child(3)->get_value(), true);

}
