#include "monty.h"

/**
 * rotl - The second element on stack becomes head and the first tail
 * @stack: double pointer to the first element in stack
 * @line_number: line number of the instruction in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *cur;

	line_number = line_number;
	tmp = *stack;
	cur = *stack;
	if (!*stack || !(*stack)->next)
		return;

	while (tmp->next)
		tmp = tmp->next;
	*stack = cur->next;
	cur->prev = tmp;
	tmp->next = cur;
	cur->next = NULL;
}
