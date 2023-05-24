#include "main.h"

/**
 * cd_file - change directory
 * @arg: directory we want to change to
 *
 * Return: 1 one success, 0 otherwise.
 */
int cd_file(char **arg)
{
	chdir(arg[1]);
	return (0);
}
