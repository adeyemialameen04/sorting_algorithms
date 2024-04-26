#include "sort.h"
#include <stdlib.h>
#include <time.h>

/**
	* selection_sort - Sorts an array with the selection sort algo.
* @array: The array to be sorted.
* @size: The size of the array.
* Return: Nothing.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		size_t min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;

			if (min_idx != i)
			{
				int tmp = array[i];

				array[i] = array[min_idx];
				array[min_idx] = tmp;
				print_array(array, size);
			}
		}
	}
}
