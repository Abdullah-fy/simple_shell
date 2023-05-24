#include "main.h"

/**
 * excute_buildin - excute buildin functions
 * @arg: commands
 *
 * Return: 1 if sucess, 0 of not
 */

int excute_buildin(char **arg)
{
        char *builtin_functions[] =
	{
		"cd", "env", "help","exit"
        };
        int (*builtin_func_code[])(char **) =
	{
		&cd_file, &env_file, &help_file, &exit_file
        };
        long unsigned int j = 0;

        if (arg[0] == NULL)
        {
                /* empty command was entered */
                return (-1);
        }
        /* find if the command is a builtin */
        for (; j < sizeof(builtin_functions) / sizeof(char *); j++)
        {
                /* if there is a match execute the builtin command */
                if (strcmp(arg[0], builtin_functions[j]) == 0)
                {
                        return ((*builtin_func_code[j])(arg));
                }
        }
        /* create a new process */
        return (excute_non_buildin(arg));
}

