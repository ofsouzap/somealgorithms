#include "sorting.h"

void sorting::array_swap(int* xs, int i1, int i2)
{
	int tmp = xs[i1];
	xs[i1] = xs[i2];
	xs[i2] = tmp;
}
