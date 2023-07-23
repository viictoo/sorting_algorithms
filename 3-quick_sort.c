#include "sort.h"

/**
 * swap - A functio n that swaps two values
 * @a: swap value
 * @b: swap value
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * lomuto_scheme- fn that partitions the array using the last element
 * as the pivot
 * @arr: --> Array to be sorted,
 * @low: --> Starting index,
 * @high: --> Ending index
 * @size: array size
 * Return: int(new last element)
*/
int lomuto_scheme(int arr[], int low, int high, size_t size)
{
	int pivot, i, j;

	/* Choosing the pivot*/
	pivot = arr[high];

	/*
	 * Index of smaller element and indicates
	 * the right position of pivot found so far
	 */
	i = (low);

	for (j = low; j <= high - 1; j++)
	{

		/*If current element is smaller than the pivot*/
		if (arr[j] < pivot)
		{

			/* Increment index of smaller element */
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			i++;
		}
	}
	if (pivot != arr[i])
	{
		swap(&arr[i], &arr[high]);
		print_array(arr, size);
	}
	return (i);
}
/**
 * recursive_sort - The main function that implements QuickSort
 * @arr: --> Array to be sorted,
 * @low: --> Starting index,
 * @high: --> Ending index
 * @size: array size
 */
void recursive_sort(int arr[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		/* pi is partitioning index, arr[p]is now at right place */
		pi = lomuto_scheme(arr, low, high, size);
		/* Separately sort elements before partition and after partition */
		recursive_sort(arr, low, pi - 1, size);
		recursive_sort(arr, pi + 1, high, size);
	}
}
/**
 * quick_sort - given entry function
 * @array: array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	recursive_sort(array, 0, (int)size - 1, size);
}
