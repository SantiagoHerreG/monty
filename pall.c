#include "monty.h"

/**
 * pall - prints the values of the stack
 * @stack: double pointer to the first node
 * @line_number: line number in the file where the opcode is located
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;

	line_number = line_number;

	if (*stack != NULL)
	{
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
