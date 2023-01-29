#pragma once

namespace mathutil
{
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
}