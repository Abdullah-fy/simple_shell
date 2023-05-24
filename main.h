#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;
void interactive(void);
void non_interactive(void);


char *reading_line(void);
char **splits(char *read);
int excute_buildin(char **arg);

int excute_non_buildin(char **arg);

char *reread(void);

void set_path(char **args);


int cd_file(char **arg);
int exit_file(char **arg);
int env_file(char **arg);
int help_file(char **arg);

#endif
