#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @n1: First node to swap
 * @n2: Second node to swap
 */
void swap(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (n1 == n2)
		return;

	if (n1->prev)
		n1->prev->next = n2;
	if (n2->next)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;

	if (n1 == *list)
		*list = n2;
}

/**
 * swap_p - Swaps two pointers in a doubly linked list
 * @list: Pointer to the head of the list
 * @p1: Pointer before the first node
 * @p2: Pointer before the second node
 */
void swap_p(listint_t **list, listint_t **p1, listint_t **p2)
{
	listint_t *p;

	if (*p1)
		(*p1)->next = *p2;
	if (*p2)
		(*p2)->prev = *p1;

	p = (*p1)->next;
	(*p1)->next = (*p2)->next;
	(*p2)->next = p;

	p = (*p1)->prev;
	(*p1)->prev = (*p2)->prev;
	(*p2)->prev = p;

	if (!*p1 && *p2)
	{
		(*p2)->prev = NULL;
		*list = *p2;
	}
	else if (!*p2 && *p1)
	{
		(*p1)->prev = NULL;
		*list = *p1;
	}

}
/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ta, *sh, *ne, *p;
	int x;

	if (!list || !(*list) || !((*list)->next))
		return;

	for (ta = *list; ta->next; ta = ta->next)

		while (1)
		{
			x = 0;
			sh = *list;
			while (sh != ta)
			{ ne = sh->next;
				if (sh->n > ne->n)
	     			{ swap(list, sh, ne);
					print_list((const listint_t *)*list);
					x = 1; }
				else
					sh = sh->next; }

			if (x == 0)
				break;
			ta = ta->prev;
			sh = ta->prev;
			while (sh)
			{
				p = sh->prev;
				if (sh->n > p->n)
				{ swap(list, sh, p);
					swap_p(list, &(sh->prev), &(p));
					if (!p)
						p = *list;
					print_list((const listint_t *)*list);
					x = 1; }
				else
					sh = sh->prev; }

			if (x == 0)
				break; }}
