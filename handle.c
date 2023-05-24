#include "main.h"

/**
 * handle_command - Tokenizes and executes a command
 *
 * @command: The command to be tokenized and executed
 */
void handle_command(char *command)
{
	char **args = malloc(100 * sizeof(char *));
	int argc = 0;
	char *arg = strtok(command, " ");

	while (arg != NULL)
	{
		args[argc++] = strdup(arg);
		arg = strtok(NULL, " ");
	}
	args[argc] = NULL;

	set_path(args);

	execute_command(args);

	free(args);
}

