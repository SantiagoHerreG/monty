#include "monty.h"
/**
 * add - function that adds the top two elements in the stack
 * @stack: double pointer to the first elemnt of the data
 * @line_number: position of the opcode in the file
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *temp;

	line_number = line_number;
	if (!*stack || !(*stack)->next)
		error_handling("add", line_number + 1);
	else
	{
		temp = *stack;
		sum = (*stack)->n;
		*stack = (*stack)->next;
		sum += (*stack)->n;
		(*stack)->n = sum;
		(*stack)->prev = NULL;
		free(temp);
	}
}
