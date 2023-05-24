#include "main.h"
/**
 * main - Runs a simple shell that can execute commands and display environment variables
 *
 * Return: 0 on success
 */
int main(void) {
extern char **environ;
   
 char *command = NULL;
    size_t command_size = 0;
    ssize_t nread_char;
    while (1) {
        printf("simple_shell$ ");
       nread_char = _getline(&command, &command_size, stdin);
        if (nread_char == -1) {
            printf("\n");
            break;
        }
        if (command[nread_char - 1] == '\n') {
            command[nread_char - 1] = '\0';
        }
        if (_strcmp(command, "exit") == 0) {
            free(command);
            exit_shell();
        } else if (_strcmp(command, "env") == 0) {
           print_env(environ);
        } else {
            handle_command(command);
        }
    }

    free(command);
    return 0;
}

