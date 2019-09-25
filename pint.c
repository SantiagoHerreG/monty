#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the first node
 * @line_number: line number in the file where the opcode is located
 * Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		error_handling("pint", line_number + 1);
	else
		printf("%d\n", (*stack)->n);
}
