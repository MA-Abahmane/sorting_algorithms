#include "sort.h"
#include <stdio.h>

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
	listint_t *copy, *temp;

	if (!(*list) || !(*list)->next || !list)
		return;

	copy = *list;

	while (copy)
	{
		while (copy->next && copy->n > copy->next->n)
		{
			temp = copy->next;
			copy->next = temp->next;
			temp->prev = copy->prev;

			if (copy->prev)
				copy->prev->next = temp;

			if (temp->next)
				temp->next->prev = copy;

			copy->prev = temp;
			temp->next = copy;

			if (temp->prev)
				copy = temp->prev;
			else
				*list = temp;

			print_list(*list);
		}
		copy = copy->next;
	}
}
