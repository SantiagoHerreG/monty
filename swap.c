#include "monty.h"

/**
 * swap - function that swaps the top two elements in the stack
 * @stack: double pointer to the first elemnt of the data
 * @line_number: position of the opcode in the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handling("swap", line_number + 1);
	else
	{
		tmp = *stack;
		if ((*stack)->next->next != NULL)
		{
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			tmp->next = (*stack)->next;
			(*stack)->next = tmp;
			tmp->next->prev = tmp;
			tmp->prev = *stack;
		}
		else
		{
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			(*stack)->next = tmp;
			tmp->prev = *stack;
			tmp->next = NULL;
		}
	}
}
