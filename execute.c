#include "monty.h"

int new_n[2];

/**
 * format - function that defines the format of the data
 * @opcode: format of the data
 * @i: Count of lines
 * Return: Continuation of i that is line
 */
unsigned int format(char **opcode, unsigned int *i)
{
	if (!strcmp("stack", opcode[0]))
	{
		new_n[1] = 0, (*i)++;
		free_array(opcode);
		return (1);
	}
	else if (!strcmp("queue", opcode[0]))
	{
		new_n[1] = 1, (*i)++;
		free_array(opcode);
		return (1);
	}
	return (0);
}
/**
 * inst_error - prints error and exits on unknown instruction
 * @args: array of arguments
 * @stack: pointer to linked list head
 * @opcode: array of words in the line
 * @i: line number
 * Return: void
 */

void inst_error(char **args, stack_t **stack, char **opcode, unsigned int i)
{
	free_array(args), free_dlist(*stack);
	fprintf(stderr, "L%u: unknown instruction %s\n", i + 1, opcode[0]);
	free_array(opcode);
	exit(EXIT_FAILURE);
}

/**
 * execute - function that executes the commands read
 * @args: array of arguments by lines
 * Return: void
 */
void execute(char **args)
{
	void (*func)(stack_t **, unsigned int);
	unsigned int i = 0;
	char *opcode[500], **tok_res;
	stack_t *stack = NULL;

	new_n[0] = 0, new_n[1] = 1;
	while (args[i])
	{
		tok_res = tokenize(args[i], " ", opcode);
		if (!tok_res)
		{
			i++;
			continue;
		}
		if (!strcmp("push", opcode[0]))
		{
			if (!opcode[1] || check_push_arg(opcode[1]))
			{
				free_array(args), free_array(opcode), free_dlist(stack);
				error_handling("push", i + 1);
			}
			new_n[0] = atoi(opcode[1]);
		}
		if (opcode[0][0] == '#')
		{
			free_array(opcode), i++;
			continue;
		}
		if (format(opcode, &i))
			continue;
		func = opcode_selector(opcode[0], i + 1);
		if (!func)
			inst_error(args, &stack, opcode, i + 1);
		func(&stack, i);
		i++, free_array(opcode);
	}
	free_array(args), free_dlist(stack);
}
