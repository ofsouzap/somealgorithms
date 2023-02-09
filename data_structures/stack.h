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

        bool is_empty()
        {
            return top == 0;
        }

        bool is_full()
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
