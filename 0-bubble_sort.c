#include "sort.h"


/**
 * bubble_sort - a function that sorts an array of integers in
 *     ascending order using the Bubble sort algorithm.
 * @array: given intiger array to sort
 * @size: the size of the array
 * 
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
unsigned long int h, i;
int val;
int flag = 0;


h = 0;
while (h < size)
{
    i = 0;
    while (i < size - h - 1)
    {
        /* if the 'current value' > 'next value'; switch values */
        if (array[i] > array[i + 1])
        {
            val = array[i];
            array[i] = array[i + 1];
            array[i + 1] = val;
            flag = 1;
        }
        print_array(array, size);
        ++i;
    }

    if (flag == 0)
        break;

    h++;
}

}