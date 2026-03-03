#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *						 ascending order using the insertion sort algorithm
 *
 * @list: a pointer to pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *current_node;

	if (!list || !(*list))
		return;

	current_node = (*list)->next;
	while (current_node)
	{
		while (current_node->prev && current_node->prev->n > current_node->n)
		{
			temp = current_node->prev->prev;

			if (temp)
				current_node->prev->prev->next = current_node;

			current_node->prev->prev = current_node;
			current_node->prev->next = current_node->next;

			if (current_node->next)
				current_node->next->prev = current_node->prev;

			current_node->next = current_node->prev;
			current_node->prev = temp;

			if (!current_node->prev)
				(*list) = current_node;

			print_list(*list);
		}

		current_node = current_node->next;
	}
}
