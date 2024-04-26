#include "sort.h"
#include <stdlib.h>

void select_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		size_t min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
		  int tmp = array[i];
		  array[i] = array[min];
		  array[min] = tmp;
		}
	}
}
