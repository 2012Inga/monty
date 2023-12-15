#include "monty.h"
/**
 * f_div - divides thesecond element from the top two elements of the stack.
 *
 * This function takes a pointer to the head of a stack and the line number
 * where the "div" instruction is encountered. It divides the value of the top
 * element from the second element from the top of the stack and updates the
 * stack accordingly. If the stack does not have at least two elements, it
 * prints an error message indicating that the stack is too short, and the
 * program exits with a failure status. If the top element is zero, it prints
 * an error message indicating division by zero and exits the program with a
 * failure status.
 *
 * @head: A double pointer to the head of the stack.
 * @counter: The line number where the "div" instruction is encountered.
 *
 * Authors :This function was originally implemented by 2012Inga.
 *
 * Return: No explicit return value.
 * Note: The function may terminate the program if the stack is too short or
 * if division by zero is attempted.
*/
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	/* Check for invalid input */
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	/* Ensure there are at least two elements in the stack*/
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
