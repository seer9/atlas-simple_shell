#include "shell.h"

/**
 * free_mem - frees all memory allocated in shell
 * @input: input string
 * @tokens: array of split input tokens
 *
 * Return: void
 */

void free_mem(char **input, char ***tokens)
{
	int i; /* counter for freeing tokens */

	if (input != NULL && *input != NULL) /* if input string exists */
	{
		free(*input);	 /* free input string */
		*input = NULL; /* clear the dangling pointer */
	}
	if (tokens != NULL && *tokens != NULL) /* if token array exists */
	{
		for (i = 0; (*tokens)[i] != NULL; i++) /* loop through array */
		{
			free((*tokens)[i]);	/* free each token */
			(*tokens)[i] = NULL; /* clear the dangling pointer */
		}
		free(*tokens);  /* free token array */
		*tokens = NULL; /* clear the dangling pointer */
	}
}
