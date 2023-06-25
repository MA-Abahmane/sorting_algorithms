#include "sort.h"


/**
 * swp - a function used to swap the values of two array positions
 * @array: given intiger array
 * @idx1: first array positions
 * @idx2: second array positions
 *
 * Return: None
 */
void swp(int *array, int idx1, int idx2)
{
int val;
val = array[idx1];
array[idx1] = array[idx2];
array[idx2] = val;
}



/**
 * shell_sort - a function that sorts an array of integers in ascending
 *   order using the Shell sort algorithm, using the Knuth sequence
 * @array: given intiger array to sort
 * @size: array size
 *
 * Return: None
 */
void shell_sort(int *array, size_t size)
{
size_t gap, i, ndx;

/* if array in unsortable; return */
if (array == NULL || size < 2)
return;

/* define the size of the gap (Knuth sequence) */
gap = 1;
while (gap < size / 3)
{
gap = gap * 3 + 1;
}

ndx = 0;
/* as we go the gap gets smaller */
for (; gap >= 1; gap /= 3)
{

/* compare the number before gap and after, in there are */
/* not in place, swap the values */
for (i = gap; i < size; i++)
{

for (ndx = i; ndx >= gap && (array[ndx] < array[ndx - gap]); ndx -= gap)
{
swp(array, ndx, (ndx - gap));
}

}
print_array(array, size);

}

}
