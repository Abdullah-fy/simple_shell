#include "main.h"

/**
 * excute_non_buildin - excute the non buildin command
 * @arg: the command line entered
 *
 * Return: 1 if success, 0 if not.
 */

int excute_non_buildin(char **arg)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* Child process */
             set_path(arg);
        if (execve(arg[0], arg, NULL) == -1) {
            perror("Error in new_process: child process");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Error forking */
        perror("Error in new_process: forking");
    } else {
        /* Parent process */
        wait(&status);
    }

    return (-1);
}


