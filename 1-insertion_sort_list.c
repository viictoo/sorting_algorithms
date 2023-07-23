#include "sort.h"
/**
 * insertion_sort_list - a function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *ff, *rw;

	if (list == NULL)
		return;

	curr = *list;

	while (curr)
	{
		if (curr->prev && curr->prev->n > curr->n)
		{
			temp = curr->prev;
			rw = temp->prev;
			curr->prev = rw;
			ff = curr->next;
			if (rw)
				rw->next = curr;
			if (ff)
				ff->prev = temp;
			curr->next = temp;
			temp->prev = curr;
			if (!ff)
				temp->next = NULL;
			if (!rw)
				*list = curr;
			temp->next = ff;
			print_list(*list);
			curr = *list;
		}

		curr = curr->next;
	}
}
