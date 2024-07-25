#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024 /* buffer size for getline */
#define TOK_SIZE 128 /* buffer size for tokens */
#define DELIM " \t\n:" /* delimiters for tokenizing input */

extern char **environ; /* environment variables */

/* Prototypes */
int main(void);
void init_shell(char **env_list, char **path, char **path_array);
void display_prompt(void);
char *read_input(void);
int tokenize_input(char *input, char ***tokens);
int handle_builtins(char *input, char **tokens, int last_status);
char *find_executable(char *command);
int execute(char **tokens);
void free_mem(char *input, char **tokens);

#endif
