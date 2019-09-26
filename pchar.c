#include "monty.h"

/**
 * pchar - Converts node value to a char
 * @stack: double pointer to the first elemnt of the data
 * @line_number: position of the opcode in the file
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int ch = 0;

	if (*stack == NULL)
		error_handling("pchar", line_number + 1);
	ch = (*stack)->n;
	if (ch >= 0 && ch <= 127)
	{
		putchar(ch);
		putchar(10);
	}
	else
		error_handling("pcharout", line_number + 1);
}
