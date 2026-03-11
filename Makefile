CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude

# target: requirements
#         target build instructions

minishell: src/main.o
	${CC} ${CFLAGS} -o minishell src/main.o

src/main.o: src/main.c
	${CC} ${CFLAGS} -c src/main.c -o src/main.o

.PHONY: clean
clean:
	rm -f src/*.o minishell
	@echo "Cleaned up the build files."