#include "shell.h"

/**
 * free_mem - frees all memory allocated in shell
 * @input: input string
 * @tokens: array of split input tokens
 * 
 * Return: void
 */

void free_mem(char *input, char **tokens)
{
	int i; /* counter for token array */

	free(input); /* free input string */
	for (i = 0; tokens[i] != NULL; i++) /* loop through array */
	{
		free(tokens[i]); /* free each token */
	}
	free(tokens); /* then free the array */
}
