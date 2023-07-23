#include "sort.h"

/**
 * shell_sort - a function that sorts an array onf integers in ascending
 * order using the knurth sequence n+1 = n * 3 + 1
 * @array: array
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (size < 2)
		return;

	while (gap < size / 3)
	{
		gap = (gap * 3) + 1;
	}

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
