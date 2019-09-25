#include "monty.h"
/**
 * pstr - prints a string of the integer into ascii decimals
 * @stack: pointer to the first node in stack
 * @line_number: line number of the argument in the file
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	line_number = line_number;
	if (!*stack)
	{
		printf("\n");
		return;
	}
	else
	{
		while (temp)
		{
			if (temp->n == 0 || temp->n < 0 || temp->n > 127)
				break;
			printf("%c", temp->n);
			temp = temp->next;
		}
		printf("\n");
	}
}
