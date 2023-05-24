#include "main.h"

/**
 * cd_file - change directory
 * @arg: directory we want to change to
 *
 * Return: 1 one success, 0 otherwise.
 */
#include <stdio.h>
#include <unistd.h>

int cd_file(char **arg)
{
    char cwd[4096];

    if (arg[1] == NULL || strcmp(arg[1], "~") == 0)
    {
        chdir(getenv("HOME"));
    }
    else if (strcmp(arg[1], "-") == 0)
    {
        chdir(getenv("OLDPWD"));
    }
    else
    {
        if (chdir(arg[1]) == -1)
        {
            perror("cd");
        }
    }

    getcwd(cwd, sizeof(cwd));
    setenv("PWD", cwd, 1);
    setenv("OLDPWD", getenv("PWD"), 1);

    return 0;
}

