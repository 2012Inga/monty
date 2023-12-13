#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include the string.h header for strcmp

#define STACK_SIZE 100

/**
 * struct Stack - A stack data structure
 * @stack: An array to store stack elements
 * @top: Index of the top element in the stack
 */
typedef struct {
    int stack[STACK_SIZE];
    int top;
} Stack;

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @value: Value to be pushed onto the stack
 */
void push(Stack *stack, int value) {
    if (stack->top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->stack[++stack->top] = value;
}

/**
 * pall - Prints all values on the stack
 * @stack: Pointer to the stack
 */
void pall(Stack *stack) {
    int i;
    for (i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->stack[i]);
    }
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    Stack stack;
    stack.top = -1; // Initialize the stack

    char opcode[4]; // Assuming the maximum opcode length is 3 (push) + 1 (null terminator)
    int value;

    while (fscanf(file, "%s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "Error: Invalid argument for push\n");
                exit(EXIT_FAILURE);
            }
            push(&stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}
