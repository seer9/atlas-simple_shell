#include "shell.h"

/**
 * find_executable - searches for executable in PATH
 * @command: command user is trying to execute
 *
 * Return: full path to executable if found, NULL if not
 */

char *find_executable(char *command)
{
	/* ptrs to PATH, dup of PATH, each directory, full path */
	char *path = NULL, *path_dup = NULL, *dir = NULL, *full_path = NULL;
	size_t path_len = 5, i ; /* length of PATH, path counter */

	for (i = 0; environ[i] != NULL; i++) /* loop through environment variables */
	{
		if (strncmp(environ[i], "PATH=", path_len) == 0) /* if variable is PATH */
		{
			path = environ[i] + path_len; /* point to the start of the PATH */
			break; /* stop looking */
		}
	}
	if (!path || !(path_dup = strdup(path))) /* if PATH not found or strdup fails */
		return (NULL); /* return NULL */
	dir = strtok(path_dup, ":"); /* split PATH into usable strings */
	while (dir != NULL) /* loop through each directory */
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2); /* for full path */
		if (full_path == NULL) /* if malloc fails */
		{
			free(path_dup); /* free the duplicate PATH */
			return (NULL); /* fail */
		}
		strcpy(full_path, dir); /* copy directory to full path */
		strcat(full_path, "/"); /* add a slash between */
		strcat(full_path, command); /* then add the command */
		if (access(full_path, X_OK) == 0) /* if file is executable */
		{
			free(path_dup); /* free the duplicate PATH */
			return (full_path); /* return the full path */
		}
		free(full_path); /* free the full path */
		dir = strtok(NULL, ":"); /* move to next directory */
	}
	free(path_dup); /* free the duplicate PATH */
	return (NULL); /* return NULL if not found */
}
