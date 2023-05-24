#include "main.h"

/**
 * splits - split the string to read the command
 * @read: the line to be split
 *
 * Return: pointer to array
 */


char **splits(char *read)
{
        int command_size = 64;
        int j = 0;
        char **tokenns = malloc(command_size * sizeof(char *));
        char *tokenn;

        if (!tokenns)
        {
                printf("error to allocate tokenn");
                exit(EXIT_FAILURE);
        }
        tokenn = strtok(read, " \n\r\a\t");
        while (tokenn != NULL)
        {
                /* handle comments */
                if (tokenn[0] == '#')
                {
                        break;
                }
                tokenns[j] = tokenn;
                j++;
                if (j >= command_size)
                {
                        command_size += command_size;
                        tokenns = realloc(tokenns, command_size * sizeof(char *));
                        if (!tokenns)
                        {
                                printf("error in realloc splited command");
                                exit(EXIT_FAILURE);
                        }
                }
                tokenn = strtok(NULL, " \n\r\t\a");
        }
        tokenns[j] = NULL;
        return (tokenns);
}

