CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -g -Iinclude
TARGET = minishell
SRCS = src/main.c src/env.c src/shell.c src/parser.c src/executor.c
BUILD_DIR = build
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o, $(SRCS))
DEPS = $(patsubst %.c,$(BUILD_DIR)/%.d, $(SRCS))

# target: requirements
#         target build instructions

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
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