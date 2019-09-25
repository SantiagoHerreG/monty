#include "monty.h"

/**
 * divi - divides the second top element by the top element of the stac
 * @stack: double pointer to the first node
 * @line_number: line number in the file where the opcode is located
*/
void divi(stack_t **stack, unsigned int line_number)
{
	int div = 0;
	stack_t *tmp;

	if(*stack == NULL || (*stack)->next == NULL)
		error_handling("div", line_number + 1);
	else if ((*stack)->n == 0)
		error_handling("divzero", line_number + 1);
	else
	{
		tmp = *stack;
		div = (*stack)->next->n;
		div /= (*stack)->n;
		*stack = (*stack)->next;
		(*stack)->n = div;
		(*stack)->prev = NULL;
		free(tmp);
	}

}
