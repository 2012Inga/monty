#include "monty.h"
#include <stdio.h>
#define _POSIX_C_SOURCE 200809L

/**
*  main - Monty code interpreter.
 *
 * This is the main entry point for the Monty code interpreter. It reads Monty
 * code from a specified file, interprets and executes each line of code,
 * and maintains the state of the stack during the process. The program exits
 * with a success status upon successful execution or with an error status if
 * there are issues with file handling or if an unknown opcode is encountered.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 *
 * Authors: Originally implemented by 2012Inga.
 *
 * Return: Returns 0 on successful execution or exits with an error status if
 * there are issues with file handling or if an unknown opcode is encountered.
 */
bus_t bus = {NULL, NULL, NULL, 0};
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	/* Validate the number of command-line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the Monty file for reading */
	file = fopen(argv[1], "r");
	bus.file = file;

	/* Handle file opening errors */
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read and execute each line of Monty code */
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}

	/* Free the stack and close the Monty file */
	free_stack(stack);
	fclose(file);
return (0);
}
