#include "monty.h"
/**
 * f_pall - Prints the elements of the stack.
 *
 * This function prints all the elements of the stack starting from the top.
 * It is designed to be used with the Monty language opcode "pall". The function
 * checks if the stack is empty before attempting to print. The counter parameter
 * is not used and included for consistency with the Monty opcode function
 * signature.
 *
 * @head: Pointer to the head of the stack.
 * @counter: Line number (not used, included for consistency).
 *
 * Authors: Originally implemented by 2012Inga.
 * Return: No return value.
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;


/* Check if the stack is empty */
	h = *head;
	if (h == NULL)
		return;

	/* Print elements of the stack starting from the top */
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
