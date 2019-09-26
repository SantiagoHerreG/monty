#include "monty.h"

/**
 * prepare_command - prepares the command to take into account empty lines
 * @command: input from the file
 * @new_command: resulting string with "#" before each \n
 * Return: void
 */

void prepare_command(char **command, char **new_command)
{
	int i = 0, j = 0;

	if (!*command)
		return;
	while ((*command)[i])
	{
		(*new_command)[j++] = (*command)[i];
		if ((*command)[i + 1])
			if ((*command)[i + 1] == '\n')
			{
				(*new_command)[j++] = ' ';
				(*new_command)[j++] = '#';
			}
		i++;
	}

}
