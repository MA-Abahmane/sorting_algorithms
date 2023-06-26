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
int i = low - 1;
int j = hight + 1;

/* select the pivot (last element) */
pvt = array[hight];

/* index in partition (set as first element) */

while (7)
{

do {
i++;
} while (array[i] < pvt);

do {
j--;
} while (array[j] > pvt);

if (i >= j)
return (j);

else
{
/* swap elements/print */
swp(array, i, j);
print_array(array, size);
}
}
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
int Pindex;

/* is end of partition is reached */
if (low < hight)
{
/* get the pivot element and sort array/partition */
/* element smaller than pivot go on left of pivot */
/* element bigger than pivot go on right of pivot */
/* return pivot index */
Pindex = partition(array, low, hight, size);

/* Now Devide And Conquer!! */
/* recursive call on the left of pivot [left partition] */
quickSort(array, low, Pindex, size);
/* recursive call on the right of pivot [right partition] */
quickSort(array, Pindex + 1, hight, size);
}
}



/**
 * quick_sort_hoare - a function that sorts an array of integers
 *   in ascending order using the Quick sort algorithm.
 * @array: given intiger array to sort
 * @size: the size of the array
 *
 * Return: None
 */
void quick_sort_hoare(int *array, size_t size)
{
/* if array in unsortable; return */
if (array == NULL || size < 2)
return;

quickSort(array, 0, size - 1, size);
}
