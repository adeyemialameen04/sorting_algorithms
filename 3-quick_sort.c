/*
 * File: 3-quick_sort.c
 */

#include "sort.h"

void swap(int *a, int *b);
int partition(int *array, size_t size, int left, int right);
void reursion(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap - Swap two nums.
 * @a: First num.
 * @b: Second num.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int left, int right)
{
	int *pivot, high, low;

	pivot = array + right;
	for (high = low = left; low < right; low++)
	{
		if (array[low] < *pivot)
		{
			if (high < low)
			{
				swap(array + low, array + high);
				print_array(array, size);
			}
			high++;
		}
	}

	if (array[high] > *pivot)
	{
		swap(array + high, pivot);
		print_array(array, size);
	}

	return (high);
}

/**
 * reursion - Implement the quicksort algorithm through recursion.
 * @array: The array to be sorted.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void reursion(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		reursion(array, size, left, part - 1);
		reursion(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array with quick sort algo.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	reursion(array, size, 0, size - 1);
}
