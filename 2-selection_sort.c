#include "sort.h"


/**
 * selection_sort - a function that sorts an array of integers in
 *      ascending order using the Selection sort algorithm.
 * @array: given intiger array to sort
 * @size: the size of the array
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
unsigned long int h, i;
int flag;
int val, min;

h = 0;
while (h < size)
{
    min = h;
    flag = 0;
    i = h + 1;
    while (i < size)
    {
        /* is index value 'i' is smaler that index value 'min'; */
        /* set 'min' to equal 'i' and raise a flag */
        if (array[min] > array[i])
        {
            min = i;
            flag = 1;
        }
        ++i;
    }
    /* switching values */
    val = array[h];
    array[h] = array[min];
    array[min] = val;


    /* if flag is raised (list updated); print array */
    if (flag != 0)
        print_array(array, size);

    h++;
    /* after the 1st smalest number is set we move on to */
    /* look for the 2end smallest number in array, and the */
    /* loop continues until all numbers are in place [min to max] */
}
}