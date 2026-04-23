#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "shell.h"
#include "env.h"
#include "parser.h"
#include "executor.h"

void mini_shell_loop(void){
    bool is_running = true;

    while (is_running){
        print_prompt();

        char *line = shell_read_line();
        if (line == NULL) break;

        char **args = shell_parse_line(line);

        is_running = shell_execute_command(args);

        // TODO: check memory cleanup practices
        // TODO: see more on helper functions for cleanup
        free(line);

        if(args != NULL){
            for(int i = 0; args[i] != NULL; i++){
                free(args[i]);
            }
            free(args);
        }
    }
}
