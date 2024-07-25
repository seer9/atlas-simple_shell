#include "shell.h"

/**
 * handle_builtins - checks if command is a builtin and executes it
 * @input: input string
 * @tokens: array of split input tokens
 * @last_status: exit status of last command
 *
 * Return: 1 if builtin found and executed, 0 if not
 */

int handle_builtins(char *input, char **tokens, int last_status)
{
	int exit_status = last_status; /* set exit status to last status */

	if (tokens[0] == NULL) /* if there's no input */
		return (0); /* indicate no builtin found */
	if (strcmp(tokens[0], "exit") == 0) /* if input is "exit" */
	{
		if (tokens[1] != NULL) /* if exit status is provided */
			exit_status = atoi(tokens[1]); /* convert to int */
		free_mem(input, tokens); /* free all memory */
		exit(exit_status); /* exit gracefully */
	}
	else if (strcmp(tokens[0], "env") == 0) /* if input is "env" */
	{
		char **env = environ; /* pointer to environment variables */

		while (*env != NULL) /* loop through environment variables */
		{
			printf("%s\n", *env); /* print each variable */
			env++; /* move to next variable */
		}
		return (1); /* indicate builtin found and executed */
	}
	return (0); /* indicate no builtin found */
}
