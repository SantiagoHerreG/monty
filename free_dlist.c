#include "monty.h"

/**
 * free_dlist - function that frees a double linked list
 * @head: pointer to the first node
 * Return: void
 */

void free_dlist(stack_t *head)
{
	stack_t *current, *temp;

	current = head;

	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
