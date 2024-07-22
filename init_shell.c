#include "shell.h"

/**
 * init_shell - initializes shell environment and finds PATH
 * @env_list: ptr to env variables
 * @path: ptr to PATH string
 * @path_array: ptr to array of PATH directories
 *
 * Return: void
 */

void init_shell(char **env_list, char **path, char **path_array)
{
	int pcounter; /* counter for path_array */
	char *path_env = NULL; /* pointer to PATH env variable */

	for (pcounter = 0; env_list[pcounter] != NULL; pcounter++) /* loop env_list */
	{
		if (strncmp(env_list[pcounter], "PATH=", 5) == 0) /* check for PATH */
		{
			path_env = env_list[pcounter]; /* store PATH env variable */
			break; /* break once PATH is found */
		}
	}
	*path = path_env; /* store PATH */
	tokenize_input(path_env, &path_array); /* tokenize PATH */
}

/* is this function even necessary given the parameters?? */
