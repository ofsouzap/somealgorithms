#pragma once

#include <exception>

using std::exception;

namespace data_structures
{

    class ChildIndexOutOfRangeException : public exception { };

    template <int N, class T>
    class NTreeNode
    {

    private:

        T value;
        NTreeNode<N, T>* children[N];

        bool child_index_in_range(int n)
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

        T get_value() const
        {
            return value;
        }

        NTreeNode<N, T>* get_child(const int n) const
        {
            return children[n];
        }

        NTreeNode<N, T>* get_left() const
        {

            if (!child_index_in_range(0))
            {
                throw ChildIndexOutOfRangeException();
            }

            return children[0];

        }

        NTreeNode<N, T>* get_right() const
        {

            if (!child_index_in_range(N-1))
            {
                throw ChildIndexOutOfRangeException();
            }

            return children[N-1];

        }

        void set_child(const int n, NTreeNode<N, T>* const child)
        {

            if (!child_index_in_range(n))
            {
                throw ChildIndexOutOfRangeException();
            }
            else
            {
                children[n] = child;
            }

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