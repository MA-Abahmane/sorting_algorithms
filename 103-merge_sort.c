#include "sort.h"

void recursive_split(int l, int r, int *array, int *process_array);
void merge_arrays(int l, int m, int r, int *dest, int *src);

/**
 * merge_sort - Sorts an array using merge algorithm
 * @array: Array to sort
 * @size: Array size
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
int i = 0, *process_array;
if (!array || size < 2)
	return;
process_array = malloc(sizeof(int) * size);
if (!process_array)
	return;
for (; i < (int)size; i++)
	process_array[i] = array[i];
recursive_split(0, size, array, process_array);
free(process_array);
}

/**
 * recursive_split - Recursively split array
 * @l: Left
 * @r: Right
 * @array: Array pointer
 * @process_array: Process array pointer
 * Return: void
 */
void recursive_split(int l, int r, int *array, int *process_array)
{
int m = 0;
if (r - l > 1)
{
	m = (l + r) / 2;
	recursive_split(l, m, array, process_array);
	recursive_split(m, r, array, process_array);
	merge_arrays(l, m, r, array, process_array);
	for (m = l; m < r; m++)
		process_array[m] = array[m];
}
}

/**
 * merge_arrays - Sort subarray and merge them
 * @l: Left
 * @m: Middle
 * @r: Right
 * @dest: Destination
 * @src: Source
 * Return: void
 */
void merge_arrays(int l, int m, int r, int *dest, int *src)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + l, m - l);
	printf("[right]: ");
	print_array(src + m, r - m);
	i = l;
	j = m;
	k = l;
	for (; k < r; k++)
	{
		if (i < m && (j >= r || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + l, r - l);
}
