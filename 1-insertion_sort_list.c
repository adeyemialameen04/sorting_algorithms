#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr = (*list)->next;
	while (curr != NULL)
	{
		listint_t *point = curr;
		int value = curr->n;

		while (point->prev != NULL && point->prev->n > value)
		{
			point->n = point->prev->n;
			point = point->prev;
		}

		point->n = value;
		print_list(*list);
		curr = curr->next;
	}
}
