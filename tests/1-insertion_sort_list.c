#include "sort.h"

void sortedInsert(listint_t **head, listint_t *new_node)
{
	listint_t *curr;

	if (*head == NULL)
		*head = new_node;
	else if ((*head)->n >= new_node->n)
	{
		new_node->next = *head;
		new_node->next->prev = new_node;
		*head = new_node;
	}
	else
	{
		curr = *head;

		while (curr->next != NULL && curr->next->n < new_node->n)
			curr = curr->next;

		new_node->next = curr->next;

		if (curr->next != NULL)
			new_node->next->prev = new_node;

		curr->next = new_node;
		new_node->prev = curr;
	}

}


void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *curr;

	if (list == NULL || *list == NULL)
		return;

	curr = *list;
	while (curr != NULL)
	{
		listint_t *next = curr->next;

		curr->prev = NULL,
		curr->next = NULL;
		sortedInsert(&sorted, curr);
		print_list(*list);
		curr = next;
	}

	*list = sorted;
}
