#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
void run_shell(void);
void handle_command(char *command);
void execute_command(char **args);
void set_path(char **args);
void exit_shell(void);
void print_environment(void);
void print_env(char **envp);
#endif /* MAIN_H */

