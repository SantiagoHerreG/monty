#include "monty.h"

/**
 * mod - Computes the rest of the division between second top and top
 * @stack: double pointer to the first node
 * @line_number: line number in the file where the opcode is located
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handling("mod", line_number + 1);
	else if ((*stack)->n == 0)
		error_handling("divzero", line_number + 1);
	else
	{
		mod = (*stack)->next->n;
		mod %= (*stack)->n;
		(*stack)->n = mod;
		pop(stack, line_number);
	}

}
