/* monty.c */

#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        execute_instruction(&stack, 0, line);  /* Adjust line_number as needed */
    }

    free(line);
    fclose(file);
    /* Clean up the stack if needed */

    return EXIT_SUCCESS;
}
