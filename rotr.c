#include "monty.h"
/**
 * rotr - modifies the stack so the last element becomes head
 * @stack: double pointer to the first element in stack
 * @line_number: line number of the instruction in the file
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;

	line_number = line_number;
	temp = *stack;
	if (!*stack || !(*stack)->next)
		return;

	while (temp->next)
		temp = temp->next;
	*stack = temp;
	temp->next = temp->prev;
	temp->prev = NULL;
	while (temp->next)
	{
		current = temp->next;
		current->next = current->prev;
		current->prev = temp;
		temp = temp->next;
	}
	temp->prev = temp->next;
	temp->next = NULL;
}
