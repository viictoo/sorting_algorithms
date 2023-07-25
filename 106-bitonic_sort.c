#include "sort.h"

/**
 * bitonic_sort -  a function that sorts an array of integers
 * in ascending order using the Bitonic sort algorithm
 * @array: The array of integers
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	bit_sort_recursive(array, size, size, true);
}

/**
 * bit_merge - Merges two subarrays inthe specified up/down direction
 * @array: The array containing the subarrays to be merged
 * @size: size of the subarrays
 * @up_down: direction of merging(1 == ascending/up, 0 == descending/down)
 */
void bit_merge(int *array, size_t size, bool up_down)
{
	size_t k, i;
	int tmp;

	if (size <= 1)
		return;
	k = size / 2;

	for (i = 0; i < k; i++)
	{
		if ((array[i] > array[i + k]) == up_down)
		{
			tmp = array[i];
			array[i] = array[i + k];
			array[i + k] = tmp;
		}
	}

	bit_merge(array, k, up_down);
	bit_merge(array + k, k, up_down);
}

/**
 * bit_sort_recursive - Recursive Bitonic sort function
 * @array: array to be sorted
 * @size: array size
 * @up_down: direction of merging(1 == ascending/up, 0 == descending/down)
 * @input_size: original array size
 */
void bit_sort_recursive(int *array, size_t size,
		size_t input_size, bool up_down)
{
	char *dir = (up_down == 1) ? "UP" : "DOWN";
	size_t k;

	if (size <= 1)
		return;

	k = size / 2;


	printf("Merging [%ld/%ld] (%s):\n", k * 2, input_size, dir);
	print_array(&array[0], k * 2);
	bit_sort_recursive(array, k, input_size,  true);
	bit_sort_recursive(array + k, k, input_size,  false);


	bit_merge(array, size, up_down);
	printf("Result [%ld/%ld] (%s):\n", size, input_size, dir);
	print_array(&array[0], k * 2);
}
