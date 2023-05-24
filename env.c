#include "main.h"

/**
 * print_env - Prints the environment
 * @envp: The environment to print
 */

void print_env(char **envp)
{
    int i = 0;

    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
}

