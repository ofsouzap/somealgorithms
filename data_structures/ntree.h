#pragma once

#include "exceptions.h"

namespace data_structures
{

    template <int N, class T>
    class NTreeNode
    {

    private:

        T value;
        NTreeNode<N, T>* children[N];

        bool child_index_in_range(int n) const
        {
            return n >= 0 && n < N;
        }

    public:

        NTreeNode(T value) : value(value)
        {

            for (int i = 0; i < N; i++)
            {
                children[i] = nullptr;
            }

        }

        ~NTreeNode()
        {

            for (int i = 0; i < N; i++)
            {
                delete children[i];
            }

        }

        T get_value() const
        {
            return value;
        }

        NTreeNode<N, T>* const get_child(const int n) const
        {
            return children[n];
        }

        NTreeNode<N, T>* const get_left() const
        {

            if (!child_index_in_range(0))
            {
                throw ChildIndexOutOfRangeException();
            }

            return children[0];

        }

        NTreeNode<N, T>* const get_right() const
        {

            if (!child_index_in_range(N-1))
            {
                throw ChildIndexOutOfRangeException();
            }

            return children[N-1];

        }

        void set_child(const int n, T child)
        {

            if (!child_index_in_range(n))
            {
                throw ChildIndexOutOfRangeException();
            }
            else
            {
                children[n] = new NTreeNode<N, T>(child);
            }

        }

        void set_left(T child)
        {

            if (!child_index_in_range(0))
            {
                throw ChildIndexOutOfRangeException();
            }

            set_child(0, child);

        }

        void set_right(T child)
        {

            if (!child_index_in_range(N-1))
            {
                throw ChildIndexOutOfRangeException();
            }

            set_child(N-1, child);

        }

        bool is_leaf() const
        {

            for (int i = 0; i < N; i++)
            {
                if (children[i] != nullptr)
                    return false;
            }

            return true;

        }

    };

    template <class T>
    using BinaryTreeNode = NTreeNode<2, T>;

}