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

        T get_value()
        {
            return value;
        }

        NTreeNode<N, T>* get_child(int n)
        {
            return children[n];
        }

        void set_child(int n, NTreeNode<N, T>* child)
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

        bool is_leaf()
        {

            for (int i = 0; i < N; i++)
            {
                if (children[i] != nullptr)
                    return false;
            }

            return true;

        }

    };

}