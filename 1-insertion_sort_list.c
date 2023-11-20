#include "sort.h"

/**
 * insertion_sort_list - insertion sorting
 *	algorithm of doubly linked list
 * @list: linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	int n;
	listint_t *tmp;

	if (!list)
		return;
	tmp = *list;
	if (tmp->next == NULL)
	{
		print_list(*list);
	}
	while (tmp)
	{
		while (tmp)
		{
			if (tmp->next)
			{
				if (tmp->n > tmp->next->n)
				{
					n = tmp->n;
					*(int *)&tmp->n = tmp->next->n;
					*(int *)&tmp->next->n = n;
					tmp = *list;

					print_list(*list);
					break;
				}
			}
			tmp = tmp->next;
		}
	}
}

