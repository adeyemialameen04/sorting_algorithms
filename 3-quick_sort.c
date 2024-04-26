#include "sort.h"
#include <stdlib.h>

void swap(int *x, int *y);
void quicksort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high);

/**
	* quick_sort - Sorts an array based on quick sort algo.
* @array: The array to be sorted.
* @size: The size of the array.
* Return: Nothing.
*/
void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size - 1, size);
}


/**
	* swap - Swap two integers.
* @x: The first val.
* @y: the second val.
* Return: Nothing
*/
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
	* quicksort_recursion - calls the partition function recursively.
* @array: The size of the array.
* @low: The beginning of the array.
* @high: The end of the array.
* @size: The size of the array.
* Return: Nothing.
*/
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high);

		quicksort_recursion(array, low, pivot_index - 1, size);
		quicksort_recursion(array, pivot_index + 1, high, size);
		print_array(array, size);
	}
}

/**
	* partition - Partitions the array.
* @array: The array.
* @low: The beginning of the array.
* @high: The end of the array.
* Return: The postion of the pivot.
*/
int partition(int *array, int low, int high)
{
	int pivot_value = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot_value)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return (i + 1);
}
