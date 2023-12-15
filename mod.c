#include "monty.h"
/**
 * f_mod - Computes the remainder of the division of the second element from the top
 *         of the stack by the top element.
 *
 *  This function takes a pointer to the head of a stack and the line number
 * where the "mod" instruction is encountered. It computes the remainder of
 * dividing the value of the second element from the top by the value of the
 * top element, updating the stack accordingly. If the stack does not have at
 * least two elements, it prints an error message indicating that the stack is
 * too short, and the program exits with a failure status. If the top element
 * is zero, it prints an error message indicating division by zero and exits
 * the program with a failure status.
 *
 * @head: A double pointer to the head of the stack.
 * @counter: The line number where the "mod" instruction is encountered.
 * Authors :This function was originally implemented by 2012Inga.
 *
 * Return:  No explicit return value.
 * Note: The function may terminate the program if the stack is too short or
 * if division by zero is attempted.
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
