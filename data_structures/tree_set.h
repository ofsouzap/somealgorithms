#pragma once

#include "exceptions.h"
#include "ntree.h"

namespace data_structures
{

    template <class T>
    class TreeSet
    {

    public:
        typedef bool (*equater_t)(const T a, const T b);
        typedef bool (*orderer_t)(const T a, const T b);

    private:

        BinaryTreeNode<T>* tree;
        equater_t equater;
        orderer_t orderer;

        void insert_aux(const T value, BinaryTreeNode<T>* const node)
        {

            if (node == nullptr)
            {
                throw InsertingIntoNullNodeException();
            }
            else
            {

                if (equater(value, node->get_value()))
                {
                    // Value already in set
                    return;
                }
                else if (orderer(value, node->get_value()))
                {
                    // Value is before the current node
                    if (node->get_left() != nullptr)
                    {
                        return insert_aux(value, node->get_left());
                    }
                    else
                    {
                        node->set_left(value);
                    }
                }
                else
                {
                    // Value is before the current node
                    if (node->get_right() != nullptr)
                    {
                        return insert_aux(value, node->get_right());
                    }
                    else
                    {
                        node->set_right(value);
                    }
                }

            }

        }

        bool find_aux(const T value, const BinaryTreeNode<T>* const node) const
        {

            if (node == nullptr)
            {
                return false;
            }
            else
            {

                if (equater(value, node->get_value()))
                {
                    // Value matches current node
                    return true;
                }
                else if (orderer_t(value, node->get_value()))
                {
                    // Value is before the current node
                    if (node->get_left() != nullptr)
                    {
                        return find_aux(value, node->get_left());
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    // Value is before the current node
                    if (node->get_right() != nullptr)
                    {
                        return find_aux(value, node->get_right());
                    }
                    else
                    {
                        return false;
                    }
                }

            }

        }


    public:

        TreeSet(equater_t equater, orderer_t orderer) : equater(equater), orderer(orderer)
        {
            tree = nullptr;
        }

        ~TreeSet()
        {
            if (tree != nullptr)
            {
                delete tree;
            }
        }

        bool is_empty() const
        {
            return tree == nullptr;
        }

        void insert(T value)
        {
            if (!is_empty())
            {
                insert_aux(value, tree);
            }
            else
            {
                tree = new BinaryTreeNode<T>(value);
            }
        }

        void find(const T value) const
        {
            return find_aux(value, tree);
        }

    };

    namespace tree_set_util
    {

        bool int_equater(const int a, const int b)
        {
            return a == b;
        }

        bool int_orderer(const int a, const int b)
        {
            return a < b;
        }

        TreeSet<int>* create_int_tree_set()
        {
            return new TreeSet<int>(int_equater, int_orderer);
        }

    }

}