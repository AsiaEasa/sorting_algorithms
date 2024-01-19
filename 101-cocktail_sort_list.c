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

    current->prev = prev ? prev->prev : NULL;
    current->next = prev;

    if (prev)
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
    current->next = next ? next->next : NULL;

    if (current->prev)
        current->prev->next = current;

    if (current->next)
        current->next->prev = current;

    if (!next)
        *list = current;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *Til, *SH;
    int CHK = 0;

    if (!list || !*list || (*list)->next == NULL)
        return;

    Til = *list;
    while (Til->next != NULL)
        Til = Til->next;

    while (!CHK)
    {
        CHK = 1;
        SH = *list;
        while (Til != SH)
        {
            if (SH->n > SH->next->n)
            {
                swap_nodes_right_to_left(list, SH);
                print_list((const listint_t *)*list);
                CHK = 0;
            }
            SH = SH->next;
        }
        for (SH = SH->prev; *list != SH; SH = SH->prev)
        {
            if (SH->n < SH->prev->n)
            {
                swap_nodes_left_to_right(list, SH->prev);
                print_list((const listint_t *)*list);
                CHK = 0;
            }
        }
    }
}
