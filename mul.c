#include "monty.h"
/**
 * f_mul - Multiplies the top two elements of the stack.
 *
 * This function multiplies the values of the top two elements in the stack,
 * updating the second element with the result. It performs proper error
 * handling, checking if the stack has at least two elements before executing
 * the multiplication operation. In case of an error, it prints an error
 * message, cleans up resources, and exits the program.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number indicating the current operation in the Monty file.
 *
 * Authors: Originally implemented by 2012Inga.
 * Return: No return value.
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;

	/* Count the number of elements in the stack */
	while (h)
	{
		h = h->next;
		len++;
	}

	 /* Check if the stack has at least two elements for multiplication */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	 /* Perform multiplication and update the second element with the result */
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
