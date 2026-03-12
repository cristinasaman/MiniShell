#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "lexer.h"

int shell_execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    // printf("--- Execution Debug ---\n");
    // for (int i = 0; args[i] != NULL; i++) {
    //     printf("args[%d]: %s\n", i, args[i]);
    // }
    // printf("-----------------------\n");

    return 1; 
}

void mini_shell_loop(){
    char *line;
    char **args;
    int status = 1;

    while (status){
        printf("> ");

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
