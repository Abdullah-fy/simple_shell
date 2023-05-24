#include "main.h"

/**
 * env_file - print enviroment variables
 * @arg: argument
 *
 * Return: 1 if success, 0 if not.
 */

int env_file(char **arg)

{
        int j = 0;
        (void)(**arg);

        while (environ[j])
        {
                write(STDOUT_FILENO, environ[j], strlen(environ[j]));
                write(STDOUT_FILENO, "\n", 1);
                j++;
        }
        return (-1);
}


