#include "sort.h"
/**
 * output - format printed output
 * @arr: input array
 * @name: name of side getting printed
 * @start: start index
 * @end: end index
 */
void output(int *arr, char *name, size_t start, size_t end)
{
	size_t i;

	printf("[%s]: ", name);
	for (i = start; i < end; i++)
	{
		if (i != (end - 1))
			printf("%d, ", arr[i]);
		else
			printf("%d\n", arr[i]);
	}

}
/**
 * merge_recursive - split and merge sorted halffs recursively
 * @array: input array
 * @arr_copy: array copy
 * @left: leftmost index
 * @right: rightmost index
 */
void merge_recursive(int *array, int *arr_copy, size_t left, size_t right)
{
	size_t i;
	size_t left_h, right_h, mid = (left + right) / 2;

	if ((right - 1) == left)
		return;

	merge_recursive(array, arr_copy, left, mid);
	merge_recursive(array, arr_copy, mid, right);
	printf("Merging...\n");
	output(array, "left", left, mid);
	output(array, "right", mid, right);

	left_h = left;
	right_h = mid;
	for (i = left; i < right; i++)
	{
		if ((left_h < mid) && ((right_h == right)
					|| (array[left_h] < array[right_h])))
		{
			arr_copy[i] = array[left_h];
			left_h++;
		}
		else
		{
			arr_copy[i] = array[right_h];
			right_h++;
		}
	}
	output(arr_copy, "Done", left, right);

	for (i = left; i < right; i++)
		array[i] = arr_copy[i];
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: input array
 * @size: array size
 */
void merge_sort(int *array, size_t size)
{
	int *arr_copy;

	if (size < 2)
		return;
	arr_copy = malloc(sizeof(int) * size);
	if (!arr_copy)
		return;

	merge_recursive(array, arr_copy, 0, size);

	free(arr_copy);
}
