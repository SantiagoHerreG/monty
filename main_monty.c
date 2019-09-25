#include "monty.h"

/*
 * main - function that opens a monty byte file and executes its lines
 * @argc: amount of arguments
 * @argv: value of the arguments
 * Return: an int
*/

int main(int argc, char **argv)
{
	char *args[1000];

	if (argc != 2)
	{/* ERROR: When no file name given or more than 1 arg */
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_read_file(argv[1], args);
	execute(args);
	
	exit_on_success();
	return (0);
}
