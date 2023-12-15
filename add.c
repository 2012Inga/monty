#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * This function takes a pointer to the head of a stack and the line number
 * where the "add" instruction os encountered. It adds the value of the top
 * two elements of the stack and updates the stack accordingly. If the stack
 * does not have at least two elements, it prints an error message indicating
 * that the stack is too short, and the program exits with a failure status.
 * @head: A duble pointer to the head of the stack.
 * @counter: The line number where the "add" instruction os encountered.
 * Authors : 2012Inga
 * Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
