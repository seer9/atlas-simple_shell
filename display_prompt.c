#include "shell.h"

/**
 * display_prompt - displays shell prompt
 *
 * Return: void
 */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO)) /* determine if using terminal */
	{
		printf("$ "); /* display prompt */
		fflush(stdout); /* flush output buffer */
	}
}
