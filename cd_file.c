#include "main.h"

/**
 * cd_file - change directory
 * @arg: directory we want to change to
 *
 * Return: 1 one success, 0 otherwise.
 */
int cd_file(char **arg)
{
	if (arg[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(arg[1]) != 0)
		{
			perror("error in own_cd.c: changing dir\n");
		}
	}
	return (-1);
}
