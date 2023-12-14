/* execute_instruction.c */

#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void execute_instruction(stack_t **stack, unsigned int line_number, char *instruction)
{
    char *opcode;
    int value;

    opcode = strtok(instruction, " \t\n");
    if (opcode == NULL)
        return;

    if (strcmp(opcode, "push") == 0)
    {
        value = atoi(strtok(NULL, " \t\n"));
        push(stack, value, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    /* Add more cases for other opcodes as needed */
}
