#include "main.h"

void execute_command(char **args)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        /* Child process */
        if (execve(args[0], args, NULL) == -1)
        {
            perror("Error executing command");
            exit(1);
        }
    }
    else if (pid > 0)
    {
        wait(&status);
    }
    else
    {
        perror("error");
    }
}

