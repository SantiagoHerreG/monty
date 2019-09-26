#include "monty.h"
/**
 * open_read_file - function that opens the file, reads and returns the args
 * @filename: name of the file passed to the program
 * @args: array of arguments tokenized by lines in the file
 * Return: void
 */
void open_read_file(char *filename, char **args)
{
	int fd, read_char = 1, i = 0;
	char *command = NULL, *new_command = NULL, **tok_result = NULL;

	args = args;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{/* ERROR: Can't open file */
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	command = malloc(100000);
	if (command == NULL)
	{/* ERROR: Can't malloc */
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 100000; i++)
		command[i] = '\0';
	read_char = read(fd, command, 99999);
	if (read_char == -1) /* ERROR: Can't read */
		exit(EXIT_FAILURE);
	new_command = malloc(100000);
	for (i = 0; i < 100000; i++)
		new_command[i] = '\0';
	if (new_command == NULL)
	{/* ERROR: Can't malloc */
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	prepare_command(&command, &new_command);

	tok_result = tokenize(new_command, "\n\t", args);
	free(new_command);
	free(command);
	if (!tok_result)
		exit_on_success();
}
