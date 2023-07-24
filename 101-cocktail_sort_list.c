#include "sort.h"
#include <stdbool.h>
/**
 * swap_nodes - a function that swaps nodes
 * @list: doubly linked list
 * @n1: node
 * @n2: node
 */

void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (*list == NULL || n1 == NULL || n2 == NULL)
		return;

	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*list = n2;

	if (n2->next != NULL)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;
	n1->prev = n2;
	n2->next = n1;
}

/**
 * cocktail_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the cocktail sort algorithm
 * @list: doubly linked list
 *
 */
void cocktail_sort_list(listint_t **list)
{

	bool swapped;
	listint_t *curr, *end;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (swapped = true; swapped;)
	{
		swapped = 0;
		for (curr = (*list)->next; curr; curr = curr->next)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				swapped = true;
				print_list(*list);
			}
			end  = curr;
		}

		if (!swapped)
			break;

		for (curr = end->prev; curr->prev; curr = curr->prev)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				swapped = true;
				print_list(*list);
			}
		}
	}
}
