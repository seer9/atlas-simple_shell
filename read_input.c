#include "shell.h"

/**
 * read_input - reads input from command line
 * 
 * Return: pointer to input string or NULL on EOF or error
 */

char *read_input(void)
{
       char *input = NULL; /* pointer where input will be stored */
       size_t input_size = 0; /* buffer size for getline */

