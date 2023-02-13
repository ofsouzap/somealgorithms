#pragma once

#include <exception>

using std::exception;

namespace data_structures
{

	class ChildIndexOutOfRangeException : public exception { };

	class QueueEmptyException : public exception { };
	class QueueFullException : public exception { };

	class StackEmptyException : public exception { };
	class StackFullException : public exception { };

	class InsertingIntoNullNodeException : public exception { };

}

