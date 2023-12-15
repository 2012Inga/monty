#include "monty.h"
/**
  *f_nop- Does nothing.
  *
  *This function serves as a placeholder for the "nop" opcode in the Monty scripting
  * language. It takes a double pointer to the head of the stack and the line number
  * where the "nop" instruction is encountered. This function does not perform any
  * operation and is designed to be a no-operation (nop) instruction. It is included
  * in the code to maintain consistency with the Monty bytecode specification.
  *
  * @head: A double pointer to the head of the stack. Unused in this function.
 * @counter: The line number where the "nop" instruction is encountered. Unused.
 *
 * Authors: This function was originally implemented by 2012Inga.
 *
 * Return: No explicit return value.
 * Note: This function intentionally does nothing and is used as a placeholder.
 * The parameters (head and counter) are included to maintain consistency with
 * other opcode functions in the code.
 */
void f_nop(stack_t **head, unsigned int counter)
{
	/*Silence compiler warnigs about unused parameters */
	(void) counter;
	(void) head;
}
