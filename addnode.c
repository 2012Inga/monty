#include "monty.h"
/**
 * addnode - add a new node to the head of the stack.
 *
 * This function creates a new node with the given value 'n' and adds it to the
 * head of the stack. If memory allocation for the new node fails, an error
 * message is printed, and the program exits with an error status. The function
 * takes a double pointer to the head of the stack and the new value 'n' as
 * parameters.
 *
 *  * @head: A double pointer to the head of the stack.
 * @n: The value to be stored in the new node.
 *
 * Authors: Originally implemented by 2012Inga.
 *
 * Return: No explicit return value. The new node is added to the modified stack.
 * If memory allocation fails, the program exits with an error status.
 */
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
