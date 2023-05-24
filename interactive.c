#include "main.h"

/**
 * interactive - takes command directly from shell
 *
 * Return: void
 */
void interactive(void)
{
    char *read;
    char **arg;
    int status = -1;


    while (status == -1)
    {
	printf("simple_prompt$ ");
       	read = reading_line(); /* read line from stdin */
        arg = splits(read); /* tokenize line */
        status = excute_buildin(arg);
        /* avoid memory leaks */
        free(read);
        free(arg);
        /* exit with status */
        if (status >= 0) {
            exit(status);
        }
        printf("simple_prompt$ "); /* print prompt symbol */
    }
}

