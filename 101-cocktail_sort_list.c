#include "sort.h"

void forward_swap(listint_t **list, listint_t **tail, listint_t **current);
void backward_swap(listint_t **list, listint_t **tail, listint_t **current);

/**
 * cocktail_sort_list - Sort double
 * linked list with cocktail_sort_list
 * algorithm
 * @list: doubly linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *copy, *tail;
	int FLAG = 0;

	if (!list || !(*list)->next)
		return;

	tail = *list;
	while (tail->next)
		tail = tail->next;

	while (!FLAG)
	{
		FLAG = 1;
		copy = *list;
		while (copy != tail)
		{
			if (copy->n > copy->next->n)
			{
				forward_swap(list, &tail, &copy);
				print_list(*list);
				FLAG = 0;
			}
			copy = copy->next;
		}
		copy = copy->prev;
		while (copy != *list)
		{
			if (copy->n < copy->prev->n)
			{
				backward_swap(list, &tail, &copy);
				print_list(*list);
				FLAG = 0;
			}
			copy = copy->prev;
		}
	}
}

/**
 * forward_swap - Swap a node with it successor
 * @list: Double linked list
 * @tail: Pointer to the tail of the list
 * @current: Current node pointer
 * Return: void
*/
void forward_swap(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev)
		(*current)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*current)->prev;
	(*current)->next = temp->next;
	if (temp->next)
		temp->next->prev = (*current);
	else
		*tail = *current;
	(*current)->prev = temp;
	temp->next = (*current);
	(*current) = temp;
}

/**
 * backward_swap - Swap a node with it predecessor
 * @list: Double linked list
 * @tail: Pointer to the tail of the list
 * @current: Current node pointer
 * Return: void
*/
void backward_swap(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next)
		(*current)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*current)->next;
	(*current)->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = (*current);
	else
		*list = *current;
	(*current)->next = temp;
	temp->prev = (*current);
	(*current) = temp;
}
