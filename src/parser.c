#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

char *shell_read_line(void){
    int buffer_size = LINE_BUFFER_SIZE;
    char *buffer = malloc(sizeof(char) * buffer_size);
    int position = 0;
    int character;
    
    if (!buffer){
        fprintf(stderr, "shell: allocation error\n"); 
        exit(EXIT_FAILURE);
    }

    while(1){
        character = getchar();

        if (character == EOF || character == '\n'){ 
            buffer[position] = '\0';
            break;
        }
        else{
            buffer[position] = character;
        }
        position++;

        if (position >= buffer_size){
            buffer_size += LINE_BUFFER_SIZE;
            buffer = realloc(buffer, buffer_size);

            if (!buffer){
                fprintf(stderr, "shell: allocation error\n"); 
                exit(EXIT_FAILURE);
            }
        }
    }
    
    return buffer;
}

char **shell_parse_line(char *line){
    int buffer_size = TOKEN_BUFFER_SIZE;
    char **tokens = malloc(sizeof(char *) * buffer_size);
    char *line_ptr = line;
    int position = 0;

    if(!tokens){
        fprintf(stderr, "shell: allocation error\n"); 
        exit(EXIT_FAILURE);
    }

    while(*line_ptr != '\0'){
        while(*line_ptr == ' '){
            line_ptr++;
        }

        if(*line_ptr == '\0') break;

        char *start = line_ptr;
        
        while(*line_ptr != ' ' && *line_ptr != '\0'){
            line_ptr++;
        }

        int token_length = line_ptr - start;
        char *token = malloc(sizeof(char) * (token_length + 1));

        if(!token){
            fprintf(stderr, "shell: allocation error\n"); 
            exit(EXIT_FAILURE);
        }

        strncpy(token, start, token_length);
        token[token_length] = '\0';

        tokens[position] = token;
        position++;

        if (position >= buffer_size){
            buffer_size += TOKEN_BUFFER_SIZE;
            tokens = realloc(tokens, sizeof(char *) * buffer_size);     

            if(!tokens){
                fprintf(stderr, "shell: allocation error\n"); 
                exit(EXIT_FAILURE);
            }
        }
    }
    tokens[position] = NULL; 

    return tokens;
}