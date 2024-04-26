#include "sort.h"
#include <stdlib.h>
#include <stdbool.h>

/**
	* bubble_sort - Function implementation for bubble sort.
* @array: The arrray to be sorted.
* @size: The size of the array.
* Return: Nothing.
*/
void bubble_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	size_t i = 0, j;
	bool swapped = false;

	do {
		swapped = false;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		i++;
	} while (swapped);
}
