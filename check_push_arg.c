#include "monty.h"
/**
 * check_push_arg - checks if the argument of push is valid
 * @str: argument
 * Return: 0 on success, 1 on error
 */

int check_push_arg(char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;

	for (; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (1);
	return (0);
}
