#include "monty.h"
/**
  * f_rotl - Rotates the stack to the top.
 *
 * This function rotates the stack to the top in the Monty interpreter.
 * It shifts all elements in the stack upward, with the first element becoming
 * the last. If the stack is empty or contains only one element, no rotation
 * occurs. The `counter` parameter represents the line number in the Monty script,
 * and it is included for consistency with other opcode functions.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number for consistency with other opcode functions (unused).
 *
 * Authors: Originally implemented by 2012Inga.
 * Return: No return value.
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;  /* No rotation for empty or single-element stack */
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
