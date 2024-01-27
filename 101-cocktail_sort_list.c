#include "sort.h"
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
 *                      using the Cocktail shaker sort algorithm.
 * @list: A pointer to the head of a doubly linked list of integers.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *start = NULL;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;

        /* Forward pass (left to right) */
        for (start = *list; start->next != end; start = start->next)
        {
            if (start->n > start->next->n)
            {
                swap_nodes(list, start, start->next);
                print_list(*list);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        /* Backward pass (right to left) */
        for (end = start; end->prev != *list; end = end->prev)
        {
            if (end->n < end->prev->n)
            {
                swap_nodes(list, end->prev, end);
                print_list(*list);
                swapped = 1;
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of a doubly linked list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;

    if (node1 == *list)
        *list = node2;
}
