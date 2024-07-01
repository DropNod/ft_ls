SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin

EXEC = $(BIN_DIR)/ft_ls
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -Werror

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o

fclean: clean
	rm -rf $(EXEC)

re: fclean all

.PHONY: all clean fclean re