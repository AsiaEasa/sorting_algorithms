/**
 * swap_ahead - Swap a node in a listint_t doubly-linked list
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @T: A pointer to the tail of the doubly-linked list.
 * @SH: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_ahead(listint_t **head, listint_t **SH, listint_t **T)
{
	listint_t *p;

	p = (*SH)->next;

	if (!((*SH)->prev))
		*head = p;
	else
		(*SH)->prev->next = p;
	p->prev = (*SH)->prev;
	(*SH)->next = p->next;
	if (!(p->next))
		*T = *SH;
	else
		p->next->prev = *SH;
	(*SH)->prev = p;
	p->next = *SH;
	*SH = p;
}

/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @T: A pointer to the tail of the doubly-linked list.
 * @SH: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_behind(listint_t **head, listint_t **SH, listint_t **T)
{
	listint_t *p;

	p = (*SH)->prev;

	if (!((*SH)->next))
		*T = p;
	else
		(*SH)->next->prev = p;
	p->next = (*SH)->next;
	(*SH)->prev = p->prev;
	if (!(p->prev))
		*head = *SH;
	else
		p->prev->next = *SH;
	(*SH)->next = p;
	p->prev = *SH;
	*SH = p;
}
