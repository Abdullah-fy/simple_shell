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
	/* if getline function has failed*/
	if (nread == -1)
	{
		/**
		* handle if we at the end of the file or the user
		* entered ctrl d
		*/
		if (feof(stdin))
		{
			/*avoid leaking of the memory*/
			free(read);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(read);
			perror("error in reading the input");
			exit()EXIT_SUCCESS;
		}
	}
	return (read);
}
