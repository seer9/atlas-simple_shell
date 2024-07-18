#include "shell.h"

int main(void)
{
       char *command = NULL;
       size_t command_size = 0;
       ssize_t num_read;

       while (1)
       {
              display_prompt(); /* display a prompt */

              num_read = getline(&command, &command_size, stdin); /* read command */

              


              /* tokenize command */

              /* execute command */

              /* free memory */
       }
/* display a prompt */

/* read command */

/* tokenize command */

/* execute command */

/* handle errors */

/* free memory */

/* terminate shell */
