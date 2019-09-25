#include "monty.h"
stack_t *new_stack;
/**
 * push - function that executes the push opcode, adds a data to the stack
 * @stack: first node of the linked list
 * @line_number: line of the file with the opcode
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	line_number =  line_number;
	new_node->n = new_stack->n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
	}
}
