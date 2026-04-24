#include <stdio.h>
#include <stdlib.h>

void print_shell_prompt(void){
    char *username = getenv("USER");
    char *hostname = getenv("HOSTNAME");
    char *directory = getenv("PWD");

    printf(username);
    printf("@");
    printf(hostname);
    printf(":");
    printf(directory);
    printf("$ ");
}