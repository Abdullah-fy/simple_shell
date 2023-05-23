#include "main.h"
/**
 * exec_cmd - execute a command
 *
 * @cmd: command string
 * @env: an array of pointers to environment variables
 */
void exec_cmd(char *cmd, char **env)
{
	char **arg = NULL;
	exec_arg *head = NULL;

	strtok(cmd, "\n");
	head = arg_list(cmd, " ");
	arg = arg_value(head);

	if (execve(arg[0], arg, env) == -1)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
}
/**
 * fork_cmd - create a child process
 *
 * @buf: command string
 * @env: an array of pointers to environment variables.
 *
 */
void fork_cmd(char *buf, char **env)
{
	char **arg = NULL;
	exec_arg *head = NULL;
	char *cmd = NULL;

	strtok(buf, "\n");
	head = arg_list(buf, " ");
	arg = arg_value(head);
	cmd = file_exist(arg[0], env);
	if (fork() == 0 && cmd)
	{
		if (execve(cmd, arg, env) == -1)
		{
			free_argv(head);
			free(arg);
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
		free(cmd);
		free_argv(head);
		free(arg);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
	}
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
	ssize_t rd = 0;

	if (isatty(STDIN_FILENO))
	{
		while (rd != EOF)
		{
			write(STDIN_FILENO, "($) ", 4);
			rd = getline(&buf, &size, stdin);
			if (rd != EOF)
			{
				fork_cmd(buf, env);
			}
		}

	}
	else
	{
		getline(&buf, &size, stdin);
		exec_cmd(buf, env);
	}
	return (0);
}
