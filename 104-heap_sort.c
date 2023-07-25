#include "sort.h"


/**
 * swap_addr - A functio n that swaps two values
 * @a: swap value
 * @b: swap value
 */
void swap_addr(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
/**
 * sift_down_recursive - repeatedly compares the root node with its children
 * and recursively sifts the element down the tree until it reaches its
 * correct position,
 * @array: the input array.
 * @size: size of the input array.
 * @root: The root node
 * @base: The base node
 */
void sift_down_recursive(int *array, size_t size, size_t base, size_t root)
{
	size_t max = root;
	size_t left_child = 2 * root + 1;
	size_t right_child = 2 * root + 2;

	/* Calculate the left and right child indices of the root. */
	/* Compare the root with its child and update 'max' if needed */

	if (left_child < base && array[left_child] > array[max])
		max = left_child;
	if (right_child < base && array[right_child] > array[max])
		max = right_child;

	/* If 'max' is not the root, swap the root with the maximum child */
	if (max != root)
	{
		swap_addr(&array[root], &array[max]);
		print_array(array, size);

		/* Recursively sift down the swapped element in its new position. */
		sift_down_recursive(array, size, base, max);
	}
}

/**
 * heap_sort -  sorts an array of integers in ascending order
 * implementing the sift-down heap sort algorithm
 * @array: array of integers
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (size < 2)
		return;

	/* Build the max heap by repeatedly calling sift_down_recursive on subtrees.*/
	for (i = (size / 2); i > 0; i--)
		sift_down_recursive(array, size, size, i - 1);

	/**
     *  Perform the heap sort by repeatedly extracting the maximum element and
	 * sifting down the remaining elements.
	 */
	for (i = size - 1; i > 0; i--)
	{
		/* Swap the root (maximum) element with the last unsorted element. */
		swap_addr(&array[0], &array[i]);
		print_array(array, size);

		/* Recursively sift down the new root to maintain the max-heap property */
		sift_down_recursive(array, size, i, 0);
	}
}
