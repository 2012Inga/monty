#include "monty.h"
/**
 * f_queue - Switches the stack mode to queue mode.
 *
 * This function switches the stack mode to queue mode in the Monty interpreter.
 * In queue mode, elements are added to the tail of the stack, and removals
 * occur from the head. The `counter` parameter represents the line number in
 * the Monty script, and it is included for consistency with other opcode functions.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number for consistency with other opcode functions (unused).
 *
 * Authors: Originally implemented by 2012Inga.
 * Return: No return value.
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head; /* Unused parameter */
	(void)counter; /* Unused parameter */
	bus.lifi = 1; /* Set stack mode to queue */
}

/**
 * addqueue - Adds a node to the tail of the stack in queue mode.
 *
 * This function adds a new node with the specified value to the tail of the stack
 * in queue mode. If the stack is empty, the new node becomes the head of the stack.
 * The `head` parameter is a pointer to the head of the stack, and `n` is the value
 * of the new node to be added.
 *
 * @head: Pointer to the head of the stack.
 * @n: Value of the new node to be added.
 *
 * Return: No return value.
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head; /* Save the current head of the stack */
	
	 /* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
