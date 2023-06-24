#include "sort.h"


/**
 * get_max - a function that compares all values of an
 *       array is search of the largest value.
 * @array: given intiger array to sort
 * @size: the size of the array
 *
 * Return: (int) largest element.
 */
int get_max(int *array, size_t size)
{
int max;
size_t i;

max = array[0];
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}


/**
 * counting_sort - a function that sorts an array of integers in
 *   ascending order using the Counting sort algorithm.
 * @array: given intiger array to sort
 * @size: the size of the array
 *
 * Return: None
 */
void counting_sort(int *array, size_t size)
{
int max, j;
size_t i;
int *count = NULL, *output = NULL;

max = get_max(array, size);
if (array == NULL || size < 2)
return;

count = malloc((max + 1) * sizeof(int));
if (count == NULL)
return;

output = malloc((size) * sizeof(int));
if (output == NULL)
{
free(count);
return;
}
/* compare each element of the array with all indexes of 'count' */
for (i = 0; i < size; i++) 
for (j = 0; j < max + 1; j++)
if (j == array[i])  /* if a match is found, incriment that index by 1 */
count[j]++;

/* for each value in count, add the previous value to it */
for (j = 1; j <= max; j++)
count[j] += count[j - 1];

print_array(count, max + 1);
/* set each element in its place */
for (i = 0; i < size; i++) 
{
output[count[array[i]] -  1] = array[i];
count[array[i]] -= 1;
}
/* update the old array to the new sorted version */
for (i = 0; i < size; i++)
array[i] = output[i];
free(count);
free(output);
}
