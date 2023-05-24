#include "main.h"
/*

    set_path() : find path of executable in PATH environment
    variable.
    args : pointer to argument list. First argument is
    modified to point to full path of executable.
    Sets args[0] to point to the full path of the executable, found
    by searching the directories listed in the PATH environment
    variable.
    */
void set_path(char **args) {
    char *path = getenv("PATH");
    char path_copy[1024];
    char *dir;
    char cmd_path[1024];
    _strcpy(path_copy, path);
    dir = strtok(path_copy, ":");
    while (dir != NULL) {
        _strcpy(cmd_path, dir);
        _strcat(cmd_path, "/");
        _strcat(cmd_path, args[0]);
        if (access(cmd_path, X_OK) == 0) {
            args[0] = cmd_path;
            break;
        }
        dir = strtok(NULL, ":");
    }
}

