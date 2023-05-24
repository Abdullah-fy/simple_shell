#include "main.h"
/*
 * set_path - funtion find the path
 *
 * Return: nothing
 */
void set_path(char **args)
{
	char *path = getenv("PATH");
	char path_copy[1024];
	char *dir;
	char cmd_path[1024];
	strcpy(path_copy, path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, args[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			args[0] = cmd_path;
			break;
		}
		dir = strtok(NULL, ":");
	}
}
