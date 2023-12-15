#include "monty.h"
/**
 * free_stack - frees a doubly linked list.
 *
 *  This function frees the memory occupied by each node in a doubly linked
 * list starting from the specified head. It iterates through the list,
 * releases the memory allocated for each node, and ensures proper cleanup.
 *
 * @head: The head of the doubly linked list (stack).
 * Authors :Originally implemented by 2012Inga.
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;

	/* Iterate through the doubly linked list and free each node */
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
