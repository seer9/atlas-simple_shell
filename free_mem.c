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

	if (input != NULL) /* if input string exists */
		free(input); /* free input string */

	if (tokens != NULL) /* if token array exists */
	{
		for (i = 0; tokens[i] != NULL; i++) /* loop through tokens */
			free(tokens[i]); /* free each token */
		free(tokens); /* free token array */
	}
}
