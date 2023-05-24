#include "main.h"

/**
 * excute_buildin - excute buildin functions
 * @arg: commands
 *
 * Return: 1 if sucess, 0 of not
 */

int excute_buildin(char **arg)
{
	char *builtin_functions[] = {"cd", "env", "help", "exit"};

	int (*builtin_func_code[])(char **) = {
		&cd_file,
		&env_file,
		&help_file,
		&exit_file
	};
	unsigned long int j = 0;

	if (arg[0] == NULL)
	{
		/* empty command was entered */
		return (-1);
	}
	/* find if the command is a builtin */
	for (; j < sizeof(builtin_functions) / sizeof(char *); j++)
	{
/*
 *  if there is a match execute the builtin command
 *
 *  The loop condition i < sizeof(builtin_func_list) / sizeof(char *)
 *  compares the value of i with the size of the builtin_func_list array
 *  divided by the size of a char* (the size of a pointer).
 *  sizeof(builtin_func_list) returns the total size of the builtin_func_list
 *  array in bytes.
 *
 *  sizeof(char *) returns the size of a char* pointer in bytes.
 *
 *  Dividing the total size of the array by the size of a pointer
 *  gives the number of elements in the array.
 **/
		if (strcmp(arg[0], builtin_functions[j]) == 0)
		{
			return ((*builtin_func_code[j])(arg));
		}
	}
	/* create a new process */
	return (excute_non_buildin(arg));
}
