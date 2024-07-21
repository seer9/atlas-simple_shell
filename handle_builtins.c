#include "shell.h"

/**
 * handle_builtins - checks if command is a builtin and executes it
 * @tokens: array of split input tokens
 *
 * Return: 1 if builtin found and executed, 0 if not
 */

int handle_builtins(char **tokens)
{
	