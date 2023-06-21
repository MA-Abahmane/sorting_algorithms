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
unsigned long int i;
int val;

i = 0;
while (i < size)
{   
    /* if the 'current value' > 'next value'; switch values */
   if (array[i] > array[i + 1])
    {
        val = array[i];
        array[i] = array[i + 1];
        array[i + 1] = val;
    }
    print_array(array, size);
    ++i;
}

}


int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}