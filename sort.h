#ifndef SORT_ME
#define SORT_ME

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void swap_addr(int *a, int *b);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

void bitonic_sort(int *array, size_t size);
void bit_merge(int *array, size_t size, bool up_down);
void bit_sort_recursive(int *array, size_t size,
size_t input_size, bool up_down);

void sift_down_recursive(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
#endif
