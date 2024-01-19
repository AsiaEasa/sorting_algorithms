#include "sort.h"
#include <stdbool.h>
/**
 * S_node_A - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @Til: A pointer .
 * @SH: A pointer  .
 */
void S_node_A(listint_t **list, listint_t **Til, listint_t **SH)
{
        listint_t *tmpe = (*SH)->next;

        if ((*SH)->prev != NULL)
                (*SH)->prev->next = tmpe;
        else
                *list = tmpe;
        tmpe->prev = (*SH)->prev;
        (*SH)->next = tmpe->next;
        if (tmpe->next != NULL)
                tmpe->next->prev = *SH;
        else
                *Til = *SH;
        (*SH)->prev = tmpe;
        tmpe->next = *SH;
        *SH = tmpe;
}

/**
 * S_node_B - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @Til: A pointer .
 * @SH: A pointer.
 */
void S_node_B(listint_t **list, listint_t **Til, listint_t **SH)
{
        listint_t *t = (*SH)->prev;

        if ((*SH)->next != NULL)
                (*SH)->next->prev = t;
        else
                *Til = t;
        t->next = (*SH)->next;
        (*SH)->prev = t->prev;
        if (t->prev != NULL)
                t->prev->next = *SH;
        else
                *list = *SH;
        (*SH)->next = t;
        t->prev = *SH;
        *SH = t;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list .
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
        listint_t *Til, *SH;
        bool CHK = false;

        if (!list || !*list || (*list)->next == NULL)
                return;

        Til = *list;
        while (Til->next != NULL)
                Til = Til->next;

        while (!CHK)
        {
                CHK = true;
                SH = *list;
                while (Til != SH)
                {
                        if (SH->n > SH->next->n)
                        {
                                S_node_A(list, &Til, &SH);
                                print_list((const listint_t *)*list);
                                CHK = false;
                        }
                        SH = SH->next;
                }
                for (SH = SH->prev; *list != SH;
                                SH = SH->prev)
                {
                        if (SH->n < SH->prev->n)
                        {
                                S_node_B(list, &Til, &SH);
                                print_list((const listint_t *)*list);
                                CHK = false;
                        }
                }
        }
}
