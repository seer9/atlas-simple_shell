#include "shell.h"

/**
 * TSSHELLIOT - 
 * 
 * Return: void
 */

void TSSHELLIOT(void)
{
	char *input = NULL; /* pointer to input string */
	char **tokens = NULL; /* array of split input tokens */
	int token_count; /* number of tokens in input */

	while (1) /* infinite looooooop */
	{
		tokens = malloc(64 * sizeof(char *)); /* malloc for input array */
		if (tokens == NULL) /* if malloc fails */
		{
			free_mem(input, tokens); /* set it free */
			exit(EXIT_FAILURE); /* burn it down */
		}
		display_prompt(); /* call display_prompt */
		input = read_input(); /* call read_input */
		if (input == NULL) /* if failed or EOF */
		{
			free_mem(input, tokens); /* set it free */
			exit(EXIT_SUCCESS); /* burn it down */
		}
		token_count = tokenize_input(input, tokens); /* call tokenize_input */
		if (token_count == -1) /* if tokenization fails */
		{
			free_mem(input, tokens); /* set it free */
			exit(EXIT_FAILURE); /* burn it down */
		}
	}
}
