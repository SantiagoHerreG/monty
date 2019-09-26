#include "monty.h"
/**
 * open_read_file - function that opens the file, reads and returns the args
 * @filename: name of the file passed to the program
 * @args: array of arguments tokenized by lines in the file
 * Return: void
 */
void open_read_file(char *filename, char **args)
{
	int fd, read_char = 1;
	char *command, *new_command, **tok_result;

	args = args;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{/* ERROR: Can't open file */
		fprintf(stderr, "Error: can't open %s", filename);
		exit(EXIT_FAILURE);
	}

	command = malloc(ARG_MAX * 100);
	if (command == NULL)
	{/* ERROR: Can't malloc */
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	read_char = read(fd, command, ARG_MAX * 100 - 1);
	if (read_char == -1) /* ERROR: Can't read */
		exit(EXIT_FAILURE);
	new_command = malloc(ARG_MAX * 100);
	if (new_command == NULL)
	{/* ERROR: Can't malloc */
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	prepare_command(&command, &new_command);

	tok_result = tokenize(new_command, "\n", args);
	free(new_command);
	free(command);
	if (!tok_result)
		exit_on_success();
}
