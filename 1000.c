/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

int get_value(deck_node_t *card)
{
    static const char *card_values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    const char *value = card->card->value;

    int i;
    for (i = 0; i < 13; ++i)
    {
        if (_strcmp(value, card_values[i]) == 0)
        {
            return i + 1 + 13 * card->card->kind;
        }
    }

    return 0;
}

/**
 * compare_cards - Compare two cards based on their values and kinds.
 * @card1: A pointer to the first deck_node_t card.
 * @card2: A pointer to the second deck_node_t card.
 *
 * Return: Positive byte difference if card1 > card2
 *         0 if card1 == card2
 *         Negative byte difference if card1 < card2
 */
int compare_cards(deck_node_t *card1, deck_node_t *card2)
{
    int value_diff = get_value(card1) - get_value(card2);

    if (value_diff == 0) {
        return card1->card->kind - card2->card->kind;
    }

    return value_diff;
}
