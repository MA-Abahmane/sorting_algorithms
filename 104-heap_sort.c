#include "sort.h"

void swap_values(int *a, int *b);
void heap(int *array, int size, int base_row_index, int root);

/**
 * swap_values - Swap two integers in an array.
 * @x: First integer
 * @y: Second integer
 * Return: void
 */
void swap_values(int *x, int *y)
{
int tmp;
tmp = *x;
*x = *y;
*y = tmp;
}

/**
 * heap_sort - a function that sorts an array of integers in
 *       ascending order using the Heap sort algorithm
 * @array: given intiger array to sort
 * @size: the size of the array
 *
 * Return: None
 */
void heap_sort(int *array, size_t size)
{
int idx;
if (!array || size < 2)
	return;
for (idx = (size / 2) - 1; idx >= 0; idx--)
	heap(array, size, size, idx);

for (idx = size - 1; idx > 0; idx--)
{
	swap_values(array, (array + idx));
	print_array(array, size);
	heap(array, size, idx, 0);
}
}

/**
 * heap - Heapify the array
 * @array: Array
 * @size: The size of the array
 * @base_row_index: Base row index
 * @root: Root index
 */
void heap(int *array, int size, int base_row_index, int root)
{
	int left, right, large;

	large = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < base_row_index && array[left] > array[large])
		large = left;
	if (right < base_row_index && array[right] > array[large])
		large = right;
	if (large != root)
	{
		swap_values(array + root, array + large);
		print_array(array, size);
		heap(array, size, base_row_index, large);
	}
}
