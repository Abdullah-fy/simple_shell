#include "main.h"

/**
 * help_file - print help
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int help_file(char **arg)
{
	char *builtin_functions[] = {"cd", "env", "help", "exit"};
	unsigned long int i = 0;
	(void)(**arg);

	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");
	for (; i < sizeof(builtin_functions) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_functions[i]);
	}
	printf("Use the man command for information on other programs.\n\n");
	return (-1);
}
