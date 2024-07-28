#include "shell.h"

/**
 * execute - executes user command
 * @tokens: array of input tokens
 *
 * Return: 0 on success, -1 on failure
 */

int execute(char **tokens)
{
	pid_t child_pid; /* process id for child */
	int status; /* termination status of child process */
	char *executable = NULL; /* pointer to path of executable */

	if (tokens[0] == NULL) /* if no command */
		return (-1); /* indicate failure */
	if (strchr(tokens[0], '/') != NULL) /* if command specifies path */
		executable = strdup(tokens[0]); /* duplicate command */
	else
		executable = find_executable(tokens[0]); /* find command in PATH */
	if (executable == NULL) /* if not found */
		return (127); /* indicate command not found */
	child_pid = fork(); /* create child process */
	if (child_pid == -1) /* if fork fails */
	{
		free(executable); /* free executable */
		return (-1); /* indicate failure */
	}
	if (child_pid == 0) /* if fork succeeds */
	{
		if (execve(executable, tokens, environ) == -1) /* replace child w command */
		{
			free(executable); /* if execve fails, free executable */
			exit(126); /* exit and indicate execution failure */
		}
	}
	else /* for parent process */
	{
		do {
			waitpid(child_pid, &status, WUNTRACED); /* wait for child */
		} while (!WIFEXITED(status) && !WIFSIGNALED(status)); /* until exited */
	}
	free(executable); /* free executable */
	return (WIFEXITED(status) ? WEXITSTATUS(status) : -1); /* get exit status or -1 */
}
