#include "sort.h"

/**
* swap - swapping two nodes
* @list: pointer to head of doubly linked list
* @node1: first node to swap
* @node2: Second node to swap
*
* Return: void
*/

void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->prev != NULL)
	node1->prev->next = node2;
else
	*list = node2;

if (node2->next != NULL)
	node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;
node1->prev = node2;
node2->next = node1;
}


/**
* cocktail_sort_list - cocktail shaker sort
* on a doubly linked list
* @list: pointer to pointer to list to sort
*
* Return: void
*/

void cocktail_sort_list(listint_t **list)
{
listint_t *front = NULL, *end = NULL;
int swapped = 1;

if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

while (swapped)
{
	swapped = 0;
	front = *list;

	while (front->next != end)
	{
		if (front->n > front->next->n)
		{
			swap(list, front, front->next);
			print_list(*list);
			swapped = 1;
		}
		else
			front = front->next;
	}

	if (swapped == 0)
		break;
	swapped = 0;
	end = front;

	while (front->prev != NULL)
	{
		if (front->n < front->prev->n)
		{
			swap(list, front->prev, front);
			print_list(*list);
			swapped = 1;
		}
		else
			front = front->prev;
	}
}
}
