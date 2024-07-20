#include "shell.h"

/**
 * read_input - reads input from command line
 * @input: ptr to input string
 * @input_size: ptr to size of input string
 * 
 * Return: 0 on success, -1 on failure
 */

int read_input(char **input, size_t *input_size)
{
       ssize_t num_read; /* number of bytes read */

       num_read = getline(input, input_size, stdin); /* take input from user */
       if (num_read == -1) /* if getline fails */
       {
              return (-1); /* return -1 on failure */
       }

       return (0); /* return 0 on success */
}
