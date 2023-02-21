#pragma once

#include "exceptions.h"

namespace data_structures
{

    template <class T>
    class Stack
    {

    private:

        int size;
        T* data;
        /// @brief Index of next free space
        int top;

    public:

        Stack(int size) : size(size)
        {

            data = new T[size];
            top = 0;

        }

        bool is_empty() const
        {
            return top == 0;
        }

        bool is_full() const
        {
            return top == size;
        }

        void push(T value)
        {

            if (is_full())
                throw StackFullException();
            else
            {
                data[top++] = value;
            }

        }

        T pop()
        {

            if (is_empty())
                throw StackEmptyException();
            else
            {
                return data[--top];
            }

        }

    };

}
