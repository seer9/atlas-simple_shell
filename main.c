#include "shell.h"

/**
 * main - displays prompt, reads input,
 * tokenizes input, and executes commands
 *
 * Return: 0 on success
 */

int main(void)
{
	char *input = NULL; /* pointer to input string */
	char **tokens = NULL; /* array of split input tokens */
	int token_count; /* number of tokens in input */

	while (1) /* infinite looooooop */
	{
		display_prompt(); /* call display_prompt */
		input = read_input(); /* call read_input */
		if (input == NULL) /* if failed or EOF */
		{
			free_mem(input, tokens); /* set it free */
			exit(EXIT_SUCCESS); /* exit gracefully */
		}
		token_count = tokenize_input(input, &tokens); /* call tokenize_input */
		if (token_count == -1) /* if tokenization fails */
		{
			free_mem(input, tokens); /* set it free */
			exit(EXIT_FAILURE); /* burn it down */
		}
		if (handle_builtins(tokens)) /* call handle_builtins */
		{
			free_mem(input, tokens); /* set it free */
			continue; /* wait for next command */
		}
		execute(tokens); /* call execute */
		free_mem(input, tokens); /* set it free */
	}
	return (0); /* exit success */
}