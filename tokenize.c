#include "monty.h"
/**
 * tokenize - splits a string into tokens using the delimiter
 * @str: string to be tokenized
 * @delim: character to be the delimiter
 * @args: resulting tokens in a malloc'ed array
 * Return: pointer to the array of tokens
 */

char **tokenize(char *str, const char *delim, char **args)
{
	int i = 0, j = 0;
	char *token = NULL;

	token = strtok(str, delim);
	if (token == NULL)
		return (NULL);

	while (token != NULL)
	{
		args[i] = malloc(100000);
		if (args[i] == NULL)
		{/* ERROR: Can't malloc */
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		for (j = 0; j < 100000; j++)
			args[i][j] = '\0';
		strcpy(args[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	return (args);
}
