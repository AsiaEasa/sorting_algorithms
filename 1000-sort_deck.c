#include "deck.h"
#include <stdlib.h>
#include <string.h>
#include "1000.c"

void bubble_sort(deck_node_t **deck, int (*compare)(deck_node_t *, deck_node_t *))
{
    int swapped;
    deck_node_t *ptr1;
    deck_node_t *lptr = NULL;
    deck_node_t *tmp;

    if (*deck == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = *deck;

        while (ptr1->next != lptr)
        {
            if (compare(ptr1, ptr1->next) > 0)
            {
                tmp = ptr1->next;
                ptr1->next = tmp->next;

                if (tmp->next != NULL)
                    tmp->next->prev = ptr1;

                tmp->prev = ptr1->prev;
                ptr1->prev = tmp;
                tmp->next = ptr1;

                if (tmp->prev != NULL)
                    tmp->prev->next = tmp;
                else
                    *deck = tmp;

                ptr1 = tmp;
                swapped = 1;
            }
            else
            {
                ptr1 = ptr1->next;
            }
        }
        lptr = ptr1;
    } while (swapped);
}
/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds using bubble sort.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
    if (!deck || !(*deck) || !((*deck)->next))
        return;

    bubble_sort(deck, compare_cards);
}
