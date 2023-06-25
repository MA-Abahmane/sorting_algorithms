#include "sort.h"

/**
 * insertion_sort_list - sorts a DLL of integers in
 * ascending order using the insertion sort
 * algorithm
 *
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *index, *copy, *prv, *crnt, *temp;

	if (!(*list) || !(*list)->next || !list)
		return;

	copy = *list;

	index = copy->next;
	while (index)
	{	
		crnt = index;
		while (crnt->prev && crnt->n < crnt->prev->n)
		{
			prv = crnt->prev;
			

			if (crnt->next)
				crnt->next->prev = prv;

			if (prv->prev)
				prv->prev->next = crnt;
			else
				*list = crnt;

			temp = prv->prev;
			prv->prev = crnt;
			prv->next = crnt->next;

			crnt->next = prv;
			crnt->prev = temp;

			print_list(*list);
		}

		index = index->next;
	}
}
