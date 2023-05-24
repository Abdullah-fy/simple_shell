#include "main.h"

/**
 * exit_file - exit terminal
 * @arg: empty
 *
 * Return: 0 to terminate the process
 */
int exit_file(char **arg)
{
		if (*arg)
	{
		buffers1(NULL, NULL);
		buffers2(NULL, NULL);
		buffers3(NULL, NULL);
		buffers4(NULL, NULL);
		buffers5(NULL);
		exit(2);
	}
	return (0);
}
