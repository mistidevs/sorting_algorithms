#include "sort.h"
/**
 * insertion_sort_list - sort out doubly linked list
 *		using insertion sort algorithm
 * @nodes: doubly linked list
 */

void insertion_sort_list(listint_t **nodes)
{
	listint_t *current = NULL, *head = NULL;

	/*if nodes is null or only one*/
	if (nodes == NULL || *nodes == NULL || (*nodes)->next == NULL)
		return;
	head = *nodes;
	head = head->next;

	while (head != NULL)
	{
		while (head->prev != NULL && head->n < head->prev->n)
		{
			current = head;
			if (head->next != NULL)
				(head->next)->prev = current->prev;
			head->prev->next = current->next;
			head = head->prev;
			current->prev = head->prev;
			current->next = head;
			if (head->prev)
				head->prev->next = current;
			head->prev = current;
			if (current->prev == NULL)
				*nodes = current;
			print_list(*nodes);
			head = head->prev;
		}
		head = head->next;
	}
}

