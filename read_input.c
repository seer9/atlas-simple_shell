#include "shell.h"

/**
 * read_input - reads, measures, and stores input string
 * 
 * Return: pointer to input string (or NULL on EOF or error)
 */

char *read_input(void)
{
	char *input = NULL; /* pointer where input will be stored */
	size_t input_size = 0; /* buffer size for getline */
	ssize_t input_len; /* result of getline */

	input_len = getline(&input, &input_size, stdin); /* get input */
	if (input_len == -1) /* if getline fails or EOF */
	{
		free(input); /* free input buffer */
		return (NULL); /* indicate failure/EOF */
	}
	if (input[input_len - 1] == '\n') /* if input ends in a new line */
	{
		input[input_len - 1] = '\0'; /* replace that with a null byte */
	}
	return (input); /* return input string */
}
