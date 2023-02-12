#include <gtest/gtest.h>
#include "tree_set.h"

using namespace data_structures;

bool char_equater(const char a, const char b)
{
    return a == b;
}

bool char_orderer(const char a, const char b)
{
    return a < b;
}

TEST(TreeSet, Init)
{

    TreeSet<int>* t_int = tree_set_util::create_int_tree_set();
    TreeSet<char> t_char = TreeSet<char>(char_equater, char_orderer);

}

TEST(TreeSet, InsertFirst)
{

    TreeSet<int>* t = tree_set_util::create_int_tree_set();
    t->insert(0);

}

TEST(TreeSet, InsertOrdered)
{

    TreeSet<int>* t = tree_set_util::create_int_tree_set();
    t->insert(0);
    t->insert(1);
    t->insert(2);
    t->insert(3);

}

TEST(TreeSet, InsertUnique)
{

    TreeSet<int>* t = tree_set_util::create_int_tree_set();
    t->insert(5);
    t->insert(2);
    t->insert(6);
    t->insert(4);
    t->insert(8);
    t->insert(1);
    t->insert(0);

}

TEST(TreeSet, InsertDuplicates)
{

    TreeSet<int>* t = tree_set_util::create_int_tree_set();
    t->insert(5);
    t->insert(0);
    t->insert(2);
    t->insert(6);
    t->insert(1);
    t->insert(4);
    t->insert(8);
    t->insert(1);
    t->insert(4);
    t->insert(0);

}


