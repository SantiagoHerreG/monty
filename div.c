#include "monty.h"

/**
 * divi - divides the second top element by the top element of the stac
 * @stack: double pointer to the first node
 * @line_number: line number in the file where the opcode is located
*/
void divi(stack_t **stack, unsigned int line_number)
{
	int div = 0;
	/*stack_t *tmp;*/

	if (*stack == NULL || (*stack)->next == NULL)
		error_handling("div", line_number + 1);

	if ((*stack)->n == 0)
		error_handling("divzero", line_number + 1);

	div = (*stack)->n;
	(*stack)->next->n /= div;
	pop(stack, line_number);

		/*tmp = (*stack)->next;
		tmp->n = tmp->n / (*stack)->n;
		pop(stack, line_number);*/
		/*free(tmp);*/
}
