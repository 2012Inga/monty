#include "monty.h"
/**
 * f_pint - Prints the value at the top of the stack.
 *
 * This function prints the value at the top of the stack. It is designed to be
 * used with the Monty language opcode "pint". The function checks if the stack
 * is empty before attempting to print. The counter parameter represents the
 * line number in the Monty script, and it is included for error reporting.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number for error reporting.
 *
 * Authors: Originally implemented by 2012Inga.
 * Return: No return value.
 */
void f_pint(stack_t **head, unsigned int counter)
{
	/* Check if the stack is empty */
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Print the value at the top of the stack */
	printf("%d\n", (*head)->n);
}
