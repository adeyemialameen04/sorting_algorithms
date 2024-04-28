#include "sort.h"

/**
 * insertion_sort_list - Sorts a dll using insertion sort.
 * @list: The list to be sorted.
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = (*list)->next;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	while (curr != NULL)
	{
		listint_t *point = curr;
		listint_t *prev = point->prev;
		/*int value = curr->n;*/

		while (prev != NULL && prev->n > point->n)
		{
			if (point->next != NULL)
				point->next->prev = prev;
			prev->next = point->next;
			point->next = prev;
			point->prev = prev->prev;
			prev->prev = point;

			if (point->prev != NULL)
				point->prev->next = point;
			else
				*list = point;

			prev = point->prev;
		}

		print_list(*list);
		curr = curr->next;
	}
}
