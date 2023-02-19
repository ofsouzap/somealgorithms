#pragma once

#include <exception>

using std::exception;

namespace mathutil
{

	class MathDomainException : exception { };

	constexpr int int_pow(int b, int n)
	{
		if (n == 0) return 1;
		else if (n == 1) return b;
		else
		{
			int rec_res = int_pow(b * b, n / 2);
			if (n % 2 == 0) return rec_res;
			else return b * rec_res;
		}
	}

	constexpr int log2_ceil(int x)
	{

		if (x <= 0)
			throw MathDomainException();

		for (int i = 0; true; i++)
		{

			int pow = int_pow(2, i);

			if (x <= pow)
				return i;

		}

	}

}