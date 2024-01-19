#include "sort.h"

/**
 * swap_nodes_right_to_left - Swap two nodes from right to left
 * @list: Pointer to the doubly linked list
 * @current: Pointer to the current node
 *
 * This function swaps the current node with its previous node.
 */
void swap_nodes_right_to_left(listint_t **list, listint_t *current)
{
	listint_t *prev = current->prev;
	listint_t *next = current->next;

	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	current->prev = prev->prev;
	current->next = prev;
	prev->prev = current;

	if (!current->prev)
		*list = current;

	if (current->next)
		current->next->prev = current;
}

/**
 * swap_nodes_left_to_right - Swap two nodes from left to right
 * @list: Pointer to the doubly linked list
 * @current: Pointer to the current node
 *
 * This function swaps the current node with its next node.
 */
void swap_nodes_left_to_right(listint_t **list, listint_t *current)
{
	listint_t *prev = current->prev;
	listint_t *next = current->next;

	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	current->prev = next;
	current->next = next->next;
	next->next = current;

	if (current->prev)
		current->prev->next = current;

	if (!next->next)
		*list = next;
}
/** 
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers. 
 * @list: A pointer to the head of a listint_t doubly-linked list. 
 */ 
void cocktail_sort_list(listint_t **list) 
{ 
	listint_t *ta, *sh; 
	int x = 0; 

	if (!list || !(*list) || !((*list)->next)) 
		return; 

	ta = *list; 
	while (ta->next) 
		ta = ta->next; 

	while (!x) 
	{ 
		x = 1; 
		sh = *list; 
		for (; sh != ta; sh = sh->next) 
		{ 
			if (sh->next->n < sh->n) 
			{ 
				swap_nodes_right_to_left (list, sh);
				print_list((const listint_t *)*list); 
				x = 0; 
			} 
		} 

		sh = ta; 
		for (; sh != *list; sh = sh->prev) 
		{ 
			if (sh->prev->n > sh->n) 
			{ 
				swap_nodes_left_to_right(list, sh);
				print_list((const listint_t *)*list); 
				x = 0; 
			} 
		} 
	} 
}
