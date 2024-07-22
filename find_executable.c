#include "shell.h"

/**
 * find_executable - searches for executable in PATH
 * @command: command user is trying to execute
 *
 * Return: full path to executable if found, NULL if not
 */

char *find_executable(char *command)
{
	char *path = NULL; /* pointer to PATH environment variable */
	char *path_dup = NULL; /* duplicate of PATH */
	char *dir = NULL; /* pointer to each directory in the PATH */
	char *full_path = NULL; /* full path to executable */

	path = getenv("PATH"); /* get the PATH environment variable */
	if (path == NULL) /* if PATH is not set */
		return (NULL); /* fail */

	path_dup = strdup(path); /* duplicate the PATH for strtok */
	if (path_dup == NULL) /* if that fails */
		return (NULL); /* say so */

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
