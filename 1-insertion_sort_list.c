#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in dll.
 * @head: A pointer to the head.
 * @node1: First node.
 * @node2: Second node.
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (node2->next != NULL)
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;

	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *nxt;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		nxt = curr->next;
		prev = curr->prev;
		while (prev != NULL && curr->n < prev->n)
		{
			swap_nodes(list, &prev, curr);
			print_list((const listint_t *)*list);
		}
		curr = nxt;
	}
}
