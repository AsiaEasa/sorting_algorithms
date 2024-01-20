#include "sort.h"

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void radix_sort(int *array, size_t size)
{
	int l, k, p, x;

	l = size;
	k = size;

	while (l > 0)
	{
		for (x = 0; x < l - 1; x++)
		{
			if ((array[x] % 10) > (array[x + 1] % 10))
			{
				p = array[x];
				array[x] = array[x + 1];
				array[x + 1] = p;
			}
		}
		l--;
	}
	print_array(array, size);

	while (k > 0)
	{
		for (x = 0; x < k - 1; x++)
		{
			if ((array[x] % 100) > (array[x + 1] % 100))
			{
				p = array[x];
				array[x] = array[x + 1];
				array[x + 1] = p;
			}
		}
		k--;
	}
	print_array(array, size);
}
