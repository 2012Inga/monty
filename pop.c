#include "monty.h"
/**
 * f_pop - prints the top from the stack
 *  This function takes a pointer to the head of a stack and the line number
 * where the "pop" instruction is encountered. It removes the top elementi from
 * the stack, updating the stack accordingly. If the stack is empty, it prints
 * an error message indicating that the stack is empty and exits the program
 * with a failure status. It also frees the memory of the removed element.
 * @head: A double pointer to the head of the stack.
 * @counter: The line number where the "pop" instruction is encountered.
 * Authors : This function was originally implemented by 2012Inga
 * Return: no explicit return value
 * Note: The function may terminate the program if the stack is empty.
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	/* Check if the stack is empty */
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*Remove the top element from the stack and free its memory */
	h = *head;
	*head = h->next;
	free(h);
}
