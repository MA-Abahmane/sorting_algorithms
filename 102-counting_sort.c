#include "sort.h"


void counting_sort(int *array, size_t size)
{
int max, j;
size_t i;
int *count = NULL, *output = NULL;


/* check if array is sortable */
if (array == NULL || size < 2)
return;

max = array[0];
for (i = 1; i < size; i++)
{
    if (array[i] > max)
        max = array[i];
}

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
/* if a match is found, incriment that index by 1 */
for (i = 0; i < size; i++)
{
    for (j = 0; j < max + 1; j++)
    {
        if (j == array[i])
            count[j]++;
    }
}

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
