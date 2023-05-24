#include "main.h"

/**
 * reading_line - read stdin
 *
 * Return: pointer to sting
 */
char *reading_line(void)
{
        char *read = NULL;
        size_t command_size = 0;
	ssize_t nread = getline(&read, &command_size, stdin);

        if (nread == -1) /* if getline fails */
        {
                if (feof(stdin)) /* test for the eof */
                {
                        free(read); /* avoid memory leaks when ctrl + d */
                        exit(EXIT_SUCCESS); /* we recieved an eof */
                }
                else
                {
                        free(read); /* avoid memory leaks when getline fails */
                        perror("error in reading the input");
                        exit(EXIT_FAILURE);
                }
        }
        return (read);
}
