#include "main.h"

/**
 * exit_file - exit terminal
 * @arg: empty
 *
 * Return: 0 to terminate the process
 */
int exit_file(char **arg)
{
	if (arg[1])
	{
		return (atoi(arg[1]));
	}
	else
	{
		return (0);
	}
}
