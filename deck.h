#ifndef DECK
#define DECK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct values_s - Structure representing card values
 *
 * @name: Name of the card value (e.g., "Ace", "Jack", "Queen", "King")
 * @val: Numeric value of the card (e.g., 1 for "Ace", 11 for "Jack", etc.)
 */
typedef struct special_values
{
	char *name;
	int value;
} spec_values;

typedef enum kind_e
{
	SPADE = 0,
	HEART = 1,
	CLUB = 2,
	DIAMOND = 3
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void print_deck(const deck_node_t *deck);
deck_node_t *init_deck(const card_t cards[52]);
void sort_deck(deck_node_t **deck);



#endif
