#include "main.h"
/**
 * exec_cmd - execute a command
 *
 * @cmd: command string
 * @env: pointer to pointer to an array of pointers to strings
 * called the "environment"
 */
void exec_cmd(char *cmd, char **env)
{
	char **arg = NULL;
	exec_arg *head = NULL;

	strtok(cmd, "\n");
	head = arg_list(cmd);
	arg = arg_value(head);

	if (execve(arg[0], arg, env) == -1)
	{
		free_argv(head);
		free(arg);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}

	free_argv(head);
	free(arg);
}
/**
 * main - Entry point
 *
 * @argc: the number of arguments passed to the program
 * @argv: pointer to an array of strings
 * @env: an array of pointers to environment variables.
 *
 * Return: always 0 in success
 */
int main(int argc __attribute__((unused)),
char *argv[] __attribute__((unused)), char *env[])
{
	char *buf = NULL;
	size_t size = 0;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			if (fork() == 0)
			{
				write(STDIN_FILENO, "($) ", 4);
				if (getline(&buf, &size, stdin) == -1)
				{
					write(STDIN_FILENO, "\n", 1);
					exit(EXIT_SUCCESS);
				}
				exec_cmd(buf, env);
				exit(EXIT_SUCCESS);
			}
			else
			{
				if (wait(NULL) == -1)
				{
					perror("Child process");
					exit(EXIT_FAILURE);
				}
			}

		}

	}
	else
	{
		getline(&buf, &size, stdin);
		exec_cmd(buf, env);
	}
	free(buf);
	return (0);
}
