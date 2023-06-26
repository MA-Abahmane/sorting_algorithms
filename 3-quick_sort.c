#include "sort.h"

/**
 * swp - a function used to swap the values of two array positions
 * @array: given intiger array
 * @idx1: first array positions
 * @idx2: second array positions
 *
 * Return: None
 */
void swp(int *array, ssize_t idx1, ssize_t idx2)
{
int val;
val = array[idx1];
array[idx1] = array[idx2];
array[idx2] = val;
}

/**
 * partition - a function that sorts an array of integers
 *  by comparing pivot to the values of the array partition.
 * @array: given intiger array to sort
 * @size: the size of the array
 * @low: first value in array partition (0)
 * @hight: last value in array partition (size - 1)
 *
 * Return: the cerrent index position
 */
int partition(int *array, ssize_t low, ssize_t hight, size_t size)
{
	int pvt;
	ssize_t i, index;

	pvt = array[hight];
	index = low;
	i = low;
	while (i < hight)
	{

		if (array[i] < pvt)
		{

			if (array[index] != array[i])
			{
				swp(array, index, i);
				print_array(array, size);
			}
			index++;
		}

		++i;
	}

	if (array[index] != array[hight])
	{
		swp(array, index, hight);
		print_array(array, size);
	}

	return (index);
}

/**
 * quickSort - a function that sorts an array of integers
 *   in ascending order using recursion.
 * @array: given intiger array to sort
 * @size: the size of the array
 * @low: first value in array (0)
 * @hight: last value in array (size - 1)
 *
 * Return: None
 */
void quickSort(int *array, ssize_t low, ssize_t hight, size_t size)
{
	ssize_t Pindex = 0;

	/* is end of partition is reached */
	if (low < hight)
	{
		Pindex = partition(array, low, hight, size);
		quickSort(array, low, Pindex - 1, size);
		quickSort(array, Pindex + 1, hight, size);
	}
}

/**
 * quick_sort - a function that sorts an array of integers
 *   in ascending order using the Quick sort algorithm.
 * @array: given intiger array to sort
 * @size: the size of the array
 *
 * Return: None
 */
void quick_sort(int *array, size_t size)
{
	/* if array in unsortable; return */
	if (array == NULL || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
