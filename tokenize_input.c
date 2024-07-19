#include "shell.h"

/* tokenize_input: tokenize input string
 * @input: input string
 * @tokens: array of tokens
 * @delims: delimiters
 * 
 * Return: number of tokens created
 */

void tokenize_input(char *input, char **tokens, char *delims)
{
	 char *token; /* pointer to token */
	 int token_counter = 0; /* counter for tokens in input string */

	 token = strtok(input, delims); /* begin tokenizing string */
	 while (token != NULL) /* loop through input string */
	 {
		  tokens[token_counter] = token; /* store token in array */
		  token = strtok(NULL, delims); /* tokenize next bit of string */
		  token_counter++; /* increment token counter */
	 }
	 tokens[token_counter] = NULL; /* set last token to NULL to terminate array */
}
