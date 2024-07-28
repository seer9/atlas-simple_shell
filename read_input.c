#include "shell.h"

static int EOF_flag; /* flag for EOF */

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

	errno = 0; /* set errno to 0 */
	input_len = getline(&input, &input_size, stdin); /* get input */
	if (input_len == -1) /* if getline fails or EOF */
	{
		free(input); /* free buffer */
		if (errno == 0) /* if EOF */
		{
			EOF_flag = 1; /* fly the EOF flag */
		}
		return (NULL); /* indicate failure */
	}
	if (input_len > 0 && input[input_len - 1] == '\n') /* if new line */
		input[input_len - 1] = '\0'; /* replace that with a null byte */

	return (input); /* return input string */
}

/**
 * check_EOF - checks if EOF was reached
 *
 * Return: 1 if EOF, 0 if not
 */

int check_EOF(void)
{
	if (EOF_flag == 1) /* if EOF flag is flying */
	{
		EOF_flag = 0; /* lower the flag */
		return (1); /* indicate EOF */
	}
	return (0); /* indicate no EOF */
}
