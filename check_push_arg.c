#include "monty.h"
/**
 * check_push_arg - checks if the argument of push is valid
 * @str: argument
 * Return: 0 on success, 1 on error
 */

int check_push_arg(char *str)
{
	int i = 0, flag = 0;

	if (!str)
		return (1);

	if (str[i] == '-' || str[i] == '+')
		i++, flag = 1;

	for (; str[i]; i++)
	{
		if (i == 0  && (str[i] < '0' || str[i] > '9'))
			return (1);
		else if (flag && i == 1 && (str[i] < '0' || str[i] > '9'))
			return (1);
		else if (str[i] < '0' || str[i] > '9')
		{
			str[i] = '\0';
			break;
		}
	}
	return (0);
}
