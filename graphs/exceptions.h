#pragma once

#include <exception>

using std::exception;

namespace graphs
{

	class InvalidNodeException : public exception { };
	class NoEdgeFoundException : public exception { };

}
