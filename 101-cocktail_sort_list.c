#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @head: Head of first node
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next)
		next->prev = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int flag = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(list, head, head->next);
				print_list(*list);
				flag = 1;
				head = head->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_nodes(list, head->prev, head);
				print_list(*list);
				flag = 1;
				head = head->next;
			}
		}
	} while (flag == 1);
}
