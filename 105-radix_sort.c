#include "sort.h"

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void radix_sort(int *array, size_t size)
{
	int l, p, x, g, max, h;

	l = size;

	if (!array || !size || size < 2)
		return;

	for (max = array[0], h = 1; h < (int)size; h++)
	{
		if (array[h] > max)
			max = array[h];
	}

	for (g = 1; max / g != 0; g *= 10)
	{
		l = size;
		while (l > 0)
		{
			for (x = 0; x < l - 1; x++)
			{
				if ((array[x] % (g * 10)) > (array[x + 1] % (g * 10)))
				{
					p = array[x];
					array[x] = array[x + 1];
					array[x + 1] = p;
				}
			}
			l--;
		}
		print_array(array, size);
	}
}
