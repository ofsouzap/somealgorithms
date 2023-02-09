#pragma once

#include <exception>

using std::exception;

namespace data_structures
{

    class StackEmptyException : public exception { };
    class StackFullException : public exception { };

    template <class T>
    class Stack
    {

    private:

        int size;
        T* data;
        /// <summary>
        /// Index of next free space
        /// </summary>
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

        void push(T value) const
        {

            if (is_full())
                throw StackFullException();
            else
            {
                data[top++] = value;
            }

        }

        T pop() const
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
