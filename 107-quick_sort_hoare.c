#include "sort.h"
#include <stdbool.h>

/**
 * partition - This function takes first element as pivot, and places
 * all the elements smaller than the pivot on the left side
 * and all the elements greater than the pivot on
 * the right side. It returns the index of the last element
 * on the smaller side
 * @arr: array
 * @lo: least index
 * @hi: highest index
 * @size: array size
 * Return: rightmost element
 **/
int partition(int arr[], int lo, int hi, size_t size)
{
	int pivot = arr[hi];
	int i = lo - 1, j = hi + 1;
	int tmp;

	while (i < j)
	{
		/**Find leftmost element greater than or equal to pivot */
		do {
			i++;
		} while (arr[i] < pivot);

		/* Find rightmost element smaller than or equal to pivot */
		do {
			j--;
		} while (arr[j] > pivot);

		/* If two pointers met. */
		if (i < j)
		{
			/* swap(arr[i], arr[j]); */
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			print_array(arr, size);
		}
	}
	return (i);
}

/**
 * hoare_scheme - The main function that implements QuickSort hoare
 * @arr: --> Array to be sorted,
 * @lo:  --> Starting index,
 * @hi:  --> Ending index
 * @size: array size
 **/

void hoare_scheme(int arr[], int lo, int hi, size_t size)
{
	int pi;

	if (hi > lo)
	{
		/*
		 * pi is partitioning index, arr[p] is now at right place
		 */
		pi = partition(arr, lo, hi, size);

		hoare_scheme(arr, lo, pi - 1, size);
		hoare_scheme(arr, pi, hi, size);
	}
}
/**
 * quick_sort_hoare - given entry function
 * @array: array
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_scheme(array, 0, size - 1, size);
}
