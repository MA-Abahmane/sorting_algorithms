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
	listint_t *index, *prv, *crnt;

	if (!(*list) || !list)
		return;


	index = *list;
	while ((index = index->next))
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

			prv->next = crnt->next;
			crnt->prev = prv->prev;

			crnt->next = prv;
			prv->prev = crnt;

			print_list(*list);
		}
	}
}
