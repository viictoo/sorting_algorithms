#include "sort.h"

/**
 * countSort - Sorts the array based on the significant digit
 * @array: input array
 * @size: Array size
 * @sig_digit: generated exponent value
 */
void countSort(int *array, size_t size, int sig_digit)
{
	int i;
	int count[10];
	int *sorted = malloc(sizeof(int) * size);

	if (sorted == NULL || count == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < 10; i++)
	{
		count[i] = 0;
	}
	/* Store count of occurrences in count array */
	for (i = 0; i < (int)size; i++)
	{
		count[(array[i] / sig_digit) % 10]++;
	}
	/* Change count[i] so that it contains the actual position of this digit */
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	/* store contents in sorted array */
	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted[count[(array[i] / sig_digit) % 10] - 1] = array[i];
		count[(array[i] / sig_digit) % 10]--;
	}
	/* duplicate sorted elements in the original array. */
	for (i = 0; i < (int)size; i++)
	{
		array[i] = sorted[i];
	}
	free(sorted);
}
/**
 * radix_sort - sort an array using radix sort algorithm
 * @array: the list to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, i;
	size_t iter;

	if (size < 2)
		return;

	/* get max value */
	for (iter = 0; iter < size; iter++)
	{
		if (array[iter] > max)
			max = array[iter];
	}

	/* counting sort on each digit using i as exponent*/
	for (i = 1; (max / i) > 0; i *= 10)
	{
		countSort(array, size, i);
		print_array(array, size);
	}
}
