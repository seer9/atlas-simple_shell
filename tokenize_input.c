#include "shell.h"

/**
 * tokenize_input: splits input string into tokens
 * @input: input string
 * @tokens: array to store split tokens
 * 
 * Return: number of tokens created
 */

int tokenize_input(char *input, char **tokens)
{
	char *token; /* pointer to token */
	int token_counter = 0; /* counter for tokens in input string */

	*tokens = malloc(64 * sizeof(char *)); /* malloc for input tokens array */
	if (*tokens == NULL) /* if malloc fails */
	{
		exit(EXIT_FAILURE); /* burn it down */
	}
	token = strtok(input, DELIM); /* start splittin' that input (DELIM set in shell.h) */
	while (token != NULL) /* loop through input string */
	{
		(*tokens)[token_counter] = strdup(token); /* store token in array */
		token_counter++; /* increment counter */
		token = strtok(NULL, DELIM); /* move to next token in string */
	}
	(*tokens)[token_counter] = NULL; /* end array */
	return (token_counter); /* return number of tokens */
}
