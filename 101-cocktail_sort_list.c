#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @head: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node1 == *head)
		*head = node2;
}

/**
 * swap_pointers - Swaps two pointers in a doubly linked list
 * @head: Pointer to the head of the list
 * @prev1: Pointer before the first node
 * @prev2: Pointer before the second node
 */
void swap_pointers(listint_t **head, listint_t **prev1, listint_t **prev2)
{
	listint_t *tmp;

	if (*prev1)
		(*prev1)->next = *prev2;
	if (*prev2)
		(*prev2)->prev = *prev1;

	tmp = (*prev1)->next;
	(*prev1)->next = (*prev2)->next;
	(*prev2)->next = tmp;

	tmp = (*prev1)->prev;
	(*prev1)->prev = (*prev2)->prev;
	(*prev2)->prev = tmp;

	if (*prev1 == NULL && *prev2 != NULL)
	{
		(*prev2)->prev = NULL;
		*head = *prev2;
	}
	else if (*prev2 == NULL && *prev1 != NULL)
	{
		(*prev1)->prev = NULL;
		*head = *prev1;
	}

}
void cocktail_sort_list(listint_t **list)
{
	listint_t *ta, *sh, *next, *prev;
	int x;

	if (!list || !(*list) || !((*list)->next))
		return;

	ta = *list;
	while (ta->next)
		ta = ta->next;

	while (1)
	{
		x = 0;
		sh = *list;
		while (sh != ta)
		{
			next = sh->next;
			if (sh->n > next->n)
			{
				swap_nodes(list, sh, next);
				print_list((const listint_t *)*list);
				x = 1;
			}
			else
			{
				sh = sh->next;
			}
		}

		if (x == 0)
			break;

		ta = ta->prev;
		sh = ta->prev;
		while (sh != NULL)
		{
			prev = sh->prev;
			if (sh->n > prev->n)
			{
				swap_nodes(list, sh, prev);
				swap_pointers(list, &(sh->prev), &(prev));
				if (prev == NULL)
					prev = *list;
				print_list((const listint_t *)*list);
				x = 1;
			}
			else
			{
				sh = sh->prev;
			}
		}

		if (x == 0)
			break;
	}
}
