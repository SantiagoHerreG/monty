#include "monty.h"

int new_n;
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
				free_array(args), free_array(opcode);
				free_dlist(stack);
				error_handling("push", i + 1);
			}
			new_n = atoi(opcode[1]);
		}
		if (opcode[0][0] == '#')
		{
			free_array(opcode);
			i++;
			continue;
		}
		func = opcode_selector(opcode[0], i + 1);
		func(&stack, i);
		i++;
		free_array(opcode);
	}
	free_array(args);
	free_dlist(stack);
}
