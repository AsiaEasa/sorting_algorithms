#include "sort.h"

#include "101.c"

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *T, *SH;
	int x = 0;
	int i;

	if (!list || !(*list) || !((*list)->next))
		return;

	for (T = *list; T->next; T = T->next)
		;

	for (i = 0; !x ; i++)
	{
		x = 1;
		SH = *list;
		while (SH != T)
		{
			if (SH->n > SH->next->n)
			{
				x = 0;
				swap_ahead(list, &SH, &T);
				print_list((const listint_t *)*list);
			}
			SH = SH->next;
		}
		SH = SH->prev;
		while (*list != SH)
		{
			if (SH->n < SH->prev->n)
			{
				x = 0;
				swap_behind(list, &SH, &T);
				print_list((const listint_t *)*list);
			}
			SH = SH->prev;
		}
	}
}
