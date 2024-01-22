#include "sort.h"

/**
 * hoare_Par - sorts pivot
 * @ar: The array to sort
 * @begin:  start of the index
 * @end: the end of index
 * @len:  array  of size
 * Return: The index of the pivot
 */

size_t hoare_Par(int *ar, ssize_t begin, ssize_t end, size_t len)
{
	int p, i, j, pivot;

	pivot = ar[end];
	i = begin - 1, j = end + 1;

	while (i < j)
	{

		while (ar[++i] < pivot);
			;


		while (ar[--j] > pivot);
			;


		/* Swap elements at i and j */
		if (i < j)
		{
			p = ar[i];
			ar[i] = ar[j];
			ar[j] = p;
			print_array(ar, len);
		}
	}
	return (i);
}
/**
 * quick_rec - sorts an array using the quick sort algorithm
 * @ar: array to sort
 * @begin: start  of index
 * @end: end of index
 * @len: array  of size
 */
void quick_rec(int *ar, int begin, int end, size_t len)
{
	size_t i_part;

	if (end - begin > 0)
	{
		i_part = hoare_Par(ar, begin, end, len);

		quick_rec(ar, begin, i_part - 1, len);
		quick_rec(ar, i_part, end, len);
	}
}


/**
 * quick_sort_hoare - sorts a list using the quick sort algotithm
 * @array: The array to  sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;

	quick_rec(array, 0, size - 1, size);
}
