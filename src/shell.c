#include <stdio.h>
#include <stdlib.h>

#include "shell.h"
#include "parser.h"
#include "executor.h"

void mini_shell_loop(void){
    char *line;
    char **args;
    int status = 1;

    char *username = getenv("USER");
    char *hostname = getenv("HOSTNAME");
    char *directory = getenv("PWD");


    while (status){
        printf(username);
        printf("@");
        printf(hostname);
        printf(":");
        printf(directory);
        printf("$ ");


        line = shell_read_line();
        args = shell_parse_line(line);
        status = shell_execute_command(args);

        free(line);
        for(int i = 0; args[i] != NULL; i++){
            free(args[i]);
        }
        free(args);
    }
}
