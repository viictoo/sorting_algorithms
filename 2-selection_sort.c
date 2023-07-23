#include "sort.h"

/**
 * selection_sort - an in place sorting algorithm
 * @array: array to be sorted
 * @size: array size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int min, tmp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				k = j;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = min;
			array[k] = tmp;
			print_array(array, size);
		}
	}
}
