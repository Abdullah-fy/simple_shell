#include "main.h"

/**
 * non_interactive - line of command interpreter
 *
 * Return: nothing
 */

void non_interactive(void)
{
        char *read;
        char **arg;
        int status = -1;

	while (status == -1)
	{
                read = reread();
                arg = splits(read); /* tokenize line */
                status = excute_buildin(arg);
                /* avoid memory leaks */
                free(read);
                free(arg);
                /* exit with status */
                if (status >= 0)
                {
                        exit(status);
                }
        }
}

