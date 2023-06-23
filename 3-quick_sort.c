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
ssize_t i, crnt = low;

/* select the pivot */
pvt = array[hight];

/* while iterating thougt the array compare pivot  'pvt'*/
/* with each element 'array[i]' */
i = low;
while (i < hight)
{

/* if an element smaller than pivot found; */
/* swap it with the greater element pointer 'i' */
if (array[i] < pvt)
{

if (array[crnt] != array[i])
{
/* swap elements/print */
swp(array, crnt, i);
print_array(array, size);
}
/* move to next element in array */
crnt++;
}

++i;
}

if (array[crnt] != array[hight])
{
/* swap elements/print */
swp(array, crnt, hight);
print_array(array, size);
}

/* return the cerrent index position */
return (crnt);
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
ssize_t point = 0;

if (low < hight)
{
/* get the pivot element */
/* element smaller than pivot go on left of pivot */
/* element bigger than pivot go on right of pivot */
point = partition(array, low, hight, size);

/* recursive call on the left of pivot */
quickSort(array, low, point - 1, size);
/* recursive call on the right of pivot */
quickSort(array, point + 1, hight, size);
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
