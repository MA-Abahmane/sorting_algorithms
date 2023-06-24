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

/* select the pivot (last element) */
pvt = array[hight];

/* index in partition (set as first element) */
index = low;

/* while iterating thougt the array compare pivot with each */
/* other element in the partition */
/* if an element < pivot; switch it with 'index' and */ 
/* increment 'index' by 1 */
i = low;
while (i < hight)
{

/* if an element smaller than pivot found; */
/* swap it with 'index' that is on the left of pivot */
if (array[i] < pvt)
{

if (array[index] != array[i])
{
/* swap elements/print */
swp(array, index, i);
print_array(array, size);
}
/* move to 'index' to the next in array */
index++;
}

++i;
}

/* now we set pivot where index is */
/* now we have: */
/* [ smaller elements < pivot < bigger elements ] */
if (array[index] != array[hight])
{
/* swap elements/print */
swp(array, index, hight);
print_array(array, size);
}

/* return the current 'index' position */
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
/* get the pivot element and sort array/partition */
/* element smaller than pivot go on left of pivot */
/* element bigger than pivot go on right of pivot */
/* return pivot index */
Pindex = partition(array, low, hight, size);

/* Now Devide And Conquer!! */
/* recursive call on the left of pivot [left partition] */
quickSort(array, low, Pindex - 1, size);
/* recursive call on the right of pivot [right partition] */
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
