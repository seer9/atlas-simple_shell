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

	path = _getenv("PATH"); /* get the PATH environment variable */
	if (path == NULL) /* if PATH is not set */
		return (NULL); /* fail */

	path_dup = strdup(path); /* duplicate the PATH for strtok */
	if (path_dup == NULL) /* if that fails */
		return (NULL); /* say so */

	dir = strtok(path_dup, ":"); /* split PATH into usable strings */
	
	