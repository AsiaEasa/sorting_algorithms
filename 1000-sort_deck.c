#include "deck.h"
#include <stdlib.h>
#include <string.h>
#include "1000.c"


/**
 * sort_deck - Sort a deck of cards
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */

void sort_deck(deck_node_t **deck)
{
	int (*com_pare)(deck_node_t *, deck_node_t *), ch;
	deck_node_t *x, *p;
	deck_node_t *y = NULL;

	if (!deck || !(*deck) || !((*deck)->next))
		return;
	com_pare = com_cards;

	do {
		ch = 0;
		x = *deck;

		while (x->next != y)
		{
			if (com_pare(x, x->next) > 0)
			{
				p = x->next;
				x->next = p->next;

				if (p->next)
					p->next->prev = x;

				p->prev = x->prev;
				x->prev = p;
				p->next = x;

				if (p->prev)
					p->prev->next = p;
				else
					*deck = p;

				x = p;
				ch = 1;
			}
			else
			{
				x = x->next;
			}}
		y = x;
	} while (ch); }
