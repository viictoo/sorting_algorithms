#include "sort.h"

/**
  * bubble_sort - sorts an array of integers in ascending order
  * @array: array to sort
  * @size: size of the array
  */

void bubble_sort(int *array, size_t size)
{
	size_t step = 0, i = 0, swapped, temp;

	if (size == 0 || size == 1)
		return;
	for (step = 0; step < size - 1; ++step)
	{
		swapped = 0;

		for (i = 0; i < size - step - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{

				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				swapped = 1;
				print_array(array, size);
			}
		}

		if (swapped == 0)
		{
			break;
		}

	}
}
