#include "monty.h"
/**
 * sub - function that substracts the top two elements in the stack
 * @stack: double pointer to the first elemnt of the data
 * @line_number: position of the opcode in the file
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int sub = 0;
	stack_t *temp;

	line_number = line_number;
	if (!*stack || !(*stack)->next)
	{
		error_handling("sub", line_number + 1);
		return;
	}
	else
	{
		temp = *stack;
		sub = -((*stack)->n);
		*stack = (*stack)->next;
		sub += (*stack)->n;
		(*stack)->n = sub;
		(*stack)->prev = NULL;
		free(temp);
	}
}
