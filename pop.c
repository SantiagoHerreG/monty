#include "monty.h"
/**
 * pop - removes an element on top of the stack
 * @stack: double pointer to the first node
 * @line_number: line number in the file where the opcode is located
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
		error_handling("pop", line_number + 1);
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
}
