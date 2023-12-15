#include "monty.h"
/**
* execute - Executes the specified opcode based on the content of a line.
 *
 * This function takes a line of content from a Monty file, tokenizes it to
 * extract the opcode and arguments, and executes the corresponding opcode
 * function. It uses a table of opcode-function pairs for matching. If an
 * unknown opcode is encountered, an error message is printed, and the program
 * exits with an error status. The function is designed to work with a stack
 * and maintains a counter to track the line number being processed.
 *
 * @content: The line content from the Monty file.
 * @stack: A double pointer to the head of the stack.
 * @counter: The current line number being processed.
 * @file: A pointer to the Monty file being read.
 *
 * Authors: Originally implemented by 2012Inga.
 *
 * Return: Returns 0 upon success, 1 if the line is a comment or empty, and
 * exits with an error status if an unknown opcode is encountered.
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	/* Table of opcode-function pairs */
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	/* Tokenize the content to extract the opcode and arguments */
	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
