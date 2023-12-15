#include "monty.h"
/**
 *  f_swap - Swaps the top two elements of the stack.
 *
 * This function swaps the values of the top two elements of the stack. It is
 * designed to be used with the Monty language opcode "swap". The function checks
 * if the stack has at least two elements before performing the swap. The counter
 * parameter represents the line number in the Monty script, and it is included
 * for error reporting.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number for error reporting.
 *
 * Authors: Originally implemented by 2012Inga.
 * Return: No return value.
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;
	
	/* Count the number of the elements in the stack */
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}

	/* Check if the stack has at least two elements for swapping */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Swap the values of the top two elements */
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
