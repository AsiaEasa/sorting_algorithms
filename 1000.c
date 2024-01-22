int sort(deck_node_t *card)
{
	static const char *card_v[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

	const char *v = card->card->value;

	int i;
	for (i = 0; i < 13; ++i)
	{
		if (strcmp(v, card_v[i]) == 0)
		{
			return i + 1 + 13 * card->card->kind;
		}
	}

	return 0;
}

int com_cards(deck_node_t *deck1, deck_node_t *deck2)
{
	int v_diff = sort(deck1) - sort(deck2);

	if (v_diff == 0) {
		return deck1->card->kind - deck2->card->kind;
	}

	return v_diff;
}
