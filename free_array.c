#include "monty.h"

/**
 * free_array - function that frees the array of opcodes
 * @opcodes: array of strings
 * Return: void
 */

void free_array(char **opcodes)
{
	int i = 0;

	if (!opcodes)
		return;
	while (opcodes[i])
		free(opcodes[i++]);
}
