#include "monty.h"

/**
 * rotr - rotates the stack to the top
 * @stack: double pointer to the first element in stack
 * @line_number: line number of the instruction in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *current;

	line_number = line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		current = *stack;

		if (!tmp->next->next)
		{
			swap(stack, line_number);
			return;
		}

		while (tmp->next && tmp->next->next)
			tmp = tmp->next;
		current = tmp->next;
		tmp->next = NULL;
		current->prev = NULL;
		current->next = *stack;
		(*stack)->prev = current;
		*stack = current;
	}
}
