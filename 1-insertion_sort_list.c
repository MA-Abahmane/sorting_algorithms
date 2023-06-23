#include "sort.h"

/**
 * insertion_sort_list - Sort in ascendant
 * order using insertion algorith
 * @list: Double linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *copy;
if (!(*list) || !(*list)->next)
	return;
copy = (*list);
swap_values(copy, copy->next);
while (copy)
{
	if (copy->prev && copy->prev->n > copy->n)
	{
		swap_values(copy->prev, copy);
		print_list(*list);
		copy = copy->prev;
	}
	else
		copy = copy->next;
}
}

/**
 * swap_values - Swap the value of two elements
 * of a double linked list
 * @first: First element
 * @second: Second element
 * Return: void
 */
void swap_values(listint_t *first, listint_t *second)
{
	int value = first->n;
	*(int *)&first->n = second->n;
	*(int *)&second->n = value;
}
