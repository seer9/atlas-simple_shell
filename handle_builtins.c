#include "shell.h"

/**
 * handle_builtins - checks if command is a builtin and executes it
 * @tokens: array of split input tokens
 *
 * Return: 1 if builtin found and executed, 0 if not
 */

int handle_builtins(char **tokens)
{
	if (tokens[0] == NULL) /* if there's no input */
		return (0); /* indicate nothing I guess */

	if (strcmp(tokens[0], "exit") == 0) /* if input is "exit" */
	{
		free_mem(input, tokens); /* free all memory */
		exit(EXIT_SUCCESS); /* exit gracefully */
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
