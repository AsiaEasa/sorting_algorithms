#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

size_t lomuto_Par(int *ar, ssize_t begin, ssize_t end, size_t len);
void quick_rec(int *ar, int begin, int end, size_t len);
void quick_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);
void swap_pointers(listint_t **list, listint_t **p1, listint_t **p2);
void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2);

void counting_sort(int *array, size_t size);

void merge_subarr(int *array, int *B, size_t big, size_t m,
		size_t small);
void merge_s(int *array, int *B, size_t big, size_t small);
void merge_sort(int *array, size_t size);

void heap_sort(int *array, size_t size);

void radix_sort(int *array, size_t size);

void bitonic_sort(int *array, size_t size);

#endif
