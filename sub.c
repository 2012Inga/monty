#include "monty.h"
/**
  *f_sub- sustracts the top element of the stack
  *
  *  This function implements the "sub" opcode in the Monty scripting language.
 * It subtracts the top element of the stack from the second top element and
 * replaces the second top element with the result. If the stack contains fewer
 * than two elements, an error message is printed, and the program exits with
 * EXIT_FAILURE. The function takes a double pointer to the head of the stack
 * and the line number where the "sub" instruction is encountered as parameters.
 *
  * * @head: A double pointer to the head of the stack.
 * @counter: The line number where the "sub" instruction is encountered.
 *
 * Authors: This function was originally implemented by 2012Inga.
 *
 * Return: No explicit return value. The result is stored in the modified stack.
 * If the stack is too short, the program exits with EXIT_FAILURE.
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
