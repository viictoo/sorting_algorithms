#ifndef DECK
#define DECK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct special_values - Structure representing card values
 * @name: name of the special card("Ace", "Jack", "Queen", "King")
 * @value: value to assign to the card
 */
typedef struct special_values
{
	char *name;
	int value;
} spec_values;

/**
 * enum kind_e - Assigns values to the card suites
 * @SPADE: = 0,
 * @HEART: = 1,
 * @CLUB: = 2,
 * @DIAMOND: = 3
 */
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
int get_card_value(const card_t *card);
void swap_nodes(deck_node_t **deck, deck_node_t *n1, deck_node_t *n2);
#endif
