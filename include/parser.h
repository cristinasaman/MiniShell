#ifndef PARSER_H
#define PARSER_H

#define LINE_BUFFER_SIZE 1024
#define TOKEN_BUFFER_SIZE 64

char *read_shell_line(void);
char **parse_shell_line(char *line);

#endif // PARSER_H