#include "deck.h"
#include <stdbool.h>
/**
 * swap_nodes - a function that swaps nodes
 * @deck: doubly linked deck
 * @n1: node
 * @n2: node
 */

void swap_nodes(deck_node_t **deck, deck_node_t *n1, deck_node_t *n2)
{
	if (*deck == NULL || n1 == NULL || n2 == NULL)
		return;

	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*deck = n2;

	if (n2->next != NULL)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}
/**
 * get_card_value - function that uses math formula to rank cards
 * @card: card
 * Return: int(card rank)
 */
int get_card_value(const card_t *card)
{
	int rank = 0, i;
	spec_values value[] = {
		{"Ace", 1},
		{"Jack", 11},
		{"Queen", 12},
		{"King", 13}
	};

	for (i = 0; i < 4; i++)
	{
		if (strcmp(card->value, value[i].name) == 0)
		{
			rank = value[i].value;
			break;
		}
	}

	if (rank == 0)
		rank = atoi(card->value);

	return (rank + (card->kind * 13));
}

/**
 * sort_deck - a function that sorts a doubly linked deck of
 * integers in ascending order using the cocktail sort algorithm
 * @deck: doubly linked deck
 */
void sort_deck(deck_node_t **deck)
{

	bool swapped;
	deck_node_t *curr, *end;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	for (swapped = true; swapped;)
	{
		swapped = 0;
		for (curr = (*deck)->next; curr; curr = curr->next)
		{
			if ((get_card_value(curr->card)) < (get_card_value(curr->prev->card)))
			{
				swap_nodes(deck, curr->prev, curr);
				swapped = true;
				/* print_deck(*deck); */
			}
			end  = curr;
		}

		if (!swapped)
			break;

		for (curr = end->prev; curr->prev; curr = curr->prev)
		{
			if ((get_card_value(curr->card)) > (get_card_value(curr->next->card)))
			{
				swap_nodes(deck, curr, curr->next);
				swapped = true;
				/* print_deck(*deck); */
			}
		}
	}
}
