#include "shell.h"

/**
 * tokenize_input - splits input string into tokens
 * @input: input string
 * @tokens: array of split input tokens
 * 
 * Return: number of tokens created or -1 on error
 */
int tokenize_input(char *input, char ***tokens)
{
	char *token; /* pointer to token */
	int token_counter = 0; /* counter for tokens in input string */
	int i; /* counter for freeing tokens */

	*tokens = malloc(64 * sizeof(char *)); /* malloc for input array */
	if (*tokens == NULL) /* if malloc fails */
		return (-1); /* indicate failure */

	token = strtok(input, DELIM); /* start splitting input (DELIM set in shell.h) */
	while (token != NULL) /* loop through input string */
	{
		(*tokens)[token_counter] = strdup(token); /* store token in array */
		if ((*tokens)[token_counter] == NULL) /* if strdup fails */
		{
			for (i = 0; i < token_counter; i++) /* loop already malloc'd tokens */
				free((*tokens)[i]); /* free each token */

			free(*tokens); /* free the array itself */
			return (-1); /* indicate failure */
		}
		token_counter++; /* increment counter */
		token = strtok(NULL, DELIM); /* move to next token in string */
	}
	(*tokens)[token_counter] = NULL; /* null-terminate the array */
	return (token_counter); /* return number of tokens */
}
