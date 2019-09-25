#include "monty.h"
/**
 * mul - function that multiplies the top two elements in the stack
 * @stack: double pointer to the first elemnt of the data
 * @line_number: position of the opcode in the file
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int mul = 0;
	stack_t *temp;

	line_number = line_number;
	if (!*stack || !(*stack)->next)
	{
		error_handling("mul", line_number + 1);
		return;
	}
	else
	{
		temp = *stack;
		mul = (*stack)->n;
		*stack = (*stack)->next;
		mul *= (*stack)->n;
		(*stack)->n = mul;
		(*stack)->prev = NULL;
		free(temp);
	}
}
