#ifndef PARSER_H
#define PARSER_H

#define LINE_BUFFER_SIZE 1024
#define TOKEN_BUFFER_SIZE 64

char *shell_read_line(void);
char **shell_parse_line(char *line);

#endif // PARSER_H