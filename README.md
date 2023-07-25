# Sorting Algorithms Summary

This README provides a summary of various sorting algorithms, highlighting their differences and features. The algorithm's name, a brief description, and its unique characteristics are presented here to highlight their individual strengths and possible use cases.

## 1. Bubble Sort

- Description: Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
- Notable Feature: Easy to implement but inefficient for large datasets due to its quadratic time complexity (O(n^2)).

## 2. Insertion Sort

- Description: Insertion Sort is a comparison-based sorting algorithm that builds a sorted list one element at a time by repeatedly inserting each unsorted element into its correct position.
- Notable Feature: Efficient for small datasets or nearly sorted arrays, with a best-case time complexity of O(n) and average-case time complexity of O(n^2).

## 3. Selection Sort

- Description: Selection Sort is a comparison-based sorting algorithm that divides the input list into a sorted and an unsorted part, repeatedly finds the minimum element from the unsorted part, and swaps it with the first element of the unsorted part.
- Notable Feature: Simple to implement, but inefficient for large datasets with a time complexity of O(n^2) in all cases.

## 4. Quick Sort

- Description: Quick Sort is a widely-used comparison-based sorting algorithm that employs the divide-and-conquer strategy. It selects a pivot element, partitions the array around the pivot, and recursively sorts the two sub-arrays.
- Notable Feature: Quick Sort has an average-case time complexity of O(n log n) but can degrade to O(n^2) in the worst case.

## 5. Shell Sort

- Description: Shell Sort is a variation of Insertion Sort that sorts elements that are far apart before progressively reducing the gap between elements to improve efficiency.
- Notable Feature: Shell Sort has an average-case time complexity of O(n log n) but depends on the chosen gap sequence.

## 6. Counting Sort

- Description: Counting Sort is a non-comparison-based integer sorting algorithm that counts the occurrences of each element in the input array and reconstructs the sorted array from the counts.
- Notable Feature: Efficient for sorting integers within a limited range, with a time complexity of O(n + k), where "k" is the range of integers.

## 7. Cocktail Sort (Bidirectional Bubble Sort)

- Description: Cocktail Sort is a variation of Bubble Sort that sorts elements in both directions, from the beginning to the end and from the end to the beginning, to improve efficiency.
- Notable Feature: Similar to Bubble Sort but may reduce the number of passes required.

## 8. Merge Sort

- Description: Merge Sort is a comparison-based sorting algorithm that divides the input array into two halves, recursively sorts them, and merges the sorted halves.
- Notable Feature: Merge Sort has a stable time complexity of O(n log n) but requires additional space for merging.

## 9. Heap Sort

- Description: Heap Sort is a comparison-based sorting algorithm that utilizes a binary heap data structure to efficiently extract the maximum (for ascending order) element and reconstruct the sorted array.
- Notable Feature: Heap Sort has a time complexity of O(n log n) and is in-place, making it memory-efficient.

## 10. Radix Sort

- Description: Radix Sort is a non-comparison-based sorting algorithm that sorts elements based on their individual digits, starting from the least significant digit to the most significant digit.
- Notable Feature: Radix Sort has a linear time complexity of O(k \* n), where "n" is the number of elements, and "k" is the number of digits in the maximum element.

## 11. Bitonic Sort

- Description: Bitonic Sort is a parallel comparison-based sorting algorithm used mainly for hardware-based parallel processing. It involves merging two sorted sub-sequences into a bitonic sequence.
- Notable Feature: Bitonic Sort has a time complexity of O(log^2 n) and is suited for parallel computing.

**Note:** The function definitions are provided in the code for brevity. Refer to the specific sorting algorithm implementations in the source code for further details. Each sorting algorithm has its best, average and worst case time complexity provided.

**Big O notation:**is a mathematical notation used to describe the growth rate of an algorithm's time complexity concerning its input size. It helps estimate how an algorithm's performance scales as the size of the input increases. The notation represents an upper bound on the algorithm's time complexity, ignoring lower-order terms and constants.

**Selecting the Best Sorting Algorithm:**
Choosing the best sorting algorithm depends on various factors, including the size of the dataset, the range of values, and whether stability is required. For small datasets, simple algorithms like Insertion Sort, or Selection Sort might suffice. For larger datasets, more efficient algorithms like Merge Sort, Quick Sort, or Heap Sort are preferable.

When the range of input values is limited, non-comparison-based algorithms like Counting Sort or Radix Sort offer linear time complexity and should be considered. Additionally, stable sorting algorithms preserve the relative order of equal elements, which is crucial in some applications.
