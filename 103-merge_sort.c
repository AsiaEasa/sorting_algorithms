#include "sort.h"

/**
 * merge_array - Sort a subarray of integers.
 * @array:subarray of an array of integers to sort.
 * @B: A buffer to store the sorted.
 * @big: The front index.
 * @m: The middle index.
 * @small: The back index.
 */
void merge_array(int *array, int *B, size_t big, size_t m,
		size_t small)
{
	size_t x, y, k = 0;

	printf("Merging...");
	printf("\n");
	printf("[left]: ");
	print_array(array + big, m - big);
	printf("[right]: ");
	print_array(array + m, small - m);

	x = big;
	y = m;
	while (x < m && y < small)
	{
		if (array[x] < array[y])
			B[k] = array[x++];
		else
			B[k] = array[y++];
		k += 1;
	}
	while (x < m)
		B[k++] = array[x++];
	while (y < small)
		B[k++] = array[y++];
	x = big;
	k = 0;
	while (x < small)
		array[x++] = B[k++];
	printf("[Done]: ");
	print_array(array + big, small - big);
}

/**
 * merge_s - Implement the merge sort algorithm through recursion.
 * @array: A subarray of an array of integers
 * @buff: A buffer to store the result.
 * @big: The front index.
 * @small: The back index.
 */
void merge_s(int *array, int *B, size_t big, size_t small)
{
	size_t m;

	if (small - big > 1)
	{
		m = big + (small - big) / 2;
		merge_s(array, B, big, m);
		merge_s(array, B, m, small);
		merge_array(array, B, big, m, small);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array:array to integers.
 * @size:size to array.
 */
void merge_sort(int *array, size_t size)
{
	int *B;

	if (!array || !size || size < 2)
		return;

	B = malloc(sizeof(int) * size);
	if (!B)
		return;

	merge_s(array, B, 0, size);

	free(B);
}
