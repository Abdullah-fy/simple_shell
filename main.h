#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#include <stdio.h>
#include<sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
typedef struct exec_arg
{
        char *str;
        struct exec_arg *next;
} exec_arg;
char **arg_value(exec_arg *head);
exec_arg *arg_list(char *buf);
void free_argv(exec_arg *head);
void exec_cmd(char *cmd, char **env);
#endif
