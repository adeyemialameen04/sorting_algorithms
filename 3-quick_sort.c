#include "sort.h"
#include <stdlib.h>

void swap(int *x, int *y);
void quicksort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high);

void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, 0, size - 1, size);
}

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

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

int partition(int *array, int low, int high)
{
	int pivot_value = array[low];
	int i = low, j = high;

	while (i < j)
	{
		while (array[i] <= pivot_value && i <= high - 1)
			i++;
		
		while (array[j] > pivot_value && j >= low + 1)
			j--;

		if (i < j)
			swap(&array[i], &array[j]);
	}

	swap(&array[low], &array[j]);
	return (j);
}
