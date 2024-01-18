#include "sort.h"

/**
 * shell_sort - Sort an array
 * using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t x, y, gap;
	int p;

	if (!array || !size || size < 2)
		return;
	gap = 1;
	while (gap < (size / 3))
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		x = gap;
		while (x < size)
		{
			y = x;
			while (y >= gap && array[y - gap] > array[y])
			{
				p = array[y];
				array[y] = array[y - gap];
				array[y - gap] = p;

				y -= gap;
			}
			x += 1;
		}
		print_array(array, size);
		gap /= 3;
	}
}
