CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -g -Iinclude
TARGET = minishell
SRCS = src/main.c src/shell.c src/lexer.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

# target: requirements
#         target build instructions

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) 
	@echo "Cleaned up the build files."

fclean: clean
	rm -f $(TARGET)
	@echo "Removed the executable."

re: fclean all

.PHONY: all clean fclean re run

# memcheck later