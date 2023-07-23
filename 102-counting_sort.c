#include "sort.h"

/**
 * counting_sort - a function that sorts an array of
 * integers in ascending order
 * Find the largest element of the array
 * The size of count must be at least (max+1)
 * Initialize count array with all zeros.
 * Store the count of each element
 * Store the cummulative count of each array
 * Find the idx of each elem of array in count array and place in output
 * Copy the sorted elements into original array
 * @array: array containing only numbers >= 0
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int *swap, *count_arr;
	int i, max = 0;
	size_t j;

	if (size < 2)
		return;
	for (j = 0; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	count_arr = malloc(sizeof(int) * (max + 1));
	if (!count_arr)
		return;

	for (i = 0; i <= max; ++i)
		count_arr[i] = 0;

	for (j = 0; j < size; j++)
		count_arr[array[j]]++;

	for (i = 1; i <= max; i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, max + 1);
	swap = malloc(sizeof(int) * size);
	if (!swap)
	{
		free(count_arr);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = swap[j];
	free(count_arr);
	free(swap);
}
