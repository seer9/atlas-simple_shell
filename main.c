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
	int last_status = 0; /* exit status of last command */

	while (1) /* infinite looooooop */
	{
		display_prompt(); /* call display_prompt */
		input = read_input(); /* call read_input */
		if (input == NULL) /* if failed or EOF */
			exit(EXIT_SUCCESS); /* exit gracefully */
		token_count = tokenize_input(input, &tokens); /* call tokenize_input */
		if (token_count == -1) /* if tokenization fails */
		{
			free_mem(input, tokens); /* set it free */
			continue; /* wait for next command */
		}
		if (handle_builtins(input, tokens, last_status) == 0) /* builtins */
		{
			last_status = execute(tokens); /* call execute */
			if (last_status == -1) /* if execution fails */
			{
				free_mem(input, tokens); /* set it free */
				continue; /* wait for next command */
			}
		}
		free_mem(input, tokens); /* set it free */
	}
	return (0); /* exit success */
}
