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
		printf("What we call the beginning is often the end.\n");
		printf("TS SHELLIOT $ "); /* display prompt */
		fflush(stdout); /* flush output buffer */
	}
}
