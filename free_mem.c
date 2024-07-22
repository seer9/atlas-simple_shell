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
		char **temp_tokens = tokens; /* pointer to token array */

		while (*temp_tokens != NULL) /* loop through token array */
		{
			free(*temp_tokens); /* free each token */
			temp_tokens++; /* move to next token */
		}
		free(tokens); /* free token array */
	}
}
