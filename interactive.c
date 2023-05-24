#include "main.h"

/**
 * interactive - takes command directly from shell
 *
 * Return: void
 */
void interactive(void)
{
    char *read;
    char **arg;
    int status = -1;


    while (status == -1)
    {
	printf("simple_prompt$ ");
	/* read the input from the user*/
       	read = reading_line();
       /*split the input */	
        arg = splits(read); 
	/*check the the input is builtin command if it is we will excute it*/
        status = excute_buildin(arg);
        /* avoid memory leaks */
        free(read);
        free(arg);
        /* if status was equal or more than zero means we excuted the code successfully and we will
	 * exit
	 * */
        if (status >= 0) {
            exit(status);
        }
    }
}

