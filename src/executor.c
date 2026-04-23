#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int shell_execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    // built
    // cd, echo, export, exit
    // cd repos 
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL){
            chdir(getenv("HOME"));
        } 
    }

    if (strcmp(args[0], "echo") == 0) {
        printf("%s\n", args[1]);
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    // external
    // ls, mkdir, grep, git

    return 1; 
}