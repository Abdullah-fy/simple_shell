#include "main.h"

/**
 * reread - read the first charcter using getchar
 *
 * Return: pointer to read line
 */

char *reread(void)
{
        int command_size = 1024;
        int j = 0;
        char *read = malloc(sizeof(char) * command_size);
        int characters;

        if (read == NULL)
        {
                printf("error allocate form sream");
                exit(EXIT_FAILURE);
        }
        while (1)
        {
                characters = getchar(); /* read first char from stream */
                if (characters == EOF)
                {
                        free(read);
                        exit(EXIT_SUCCESS);
                }
                else if (characters == '\n')
                {
                        read[j] = '\0';
                        return (read);
                }
                else
                {
                        read[j] = characters;
                }
                j++;
                if (j >= command_size)
                {
                        command_size += command_size;
                        read = realloc(read, command_size);
                        if (read == NULL)
                        {
                                printf("realloc error");
                                exit(EXIT_FAILURE);
                        }
                }
        }
}
