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

}
