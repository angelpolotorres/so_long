
NAME = so_long

# Directories
SRC_DIR = src
OBJ_DIR = build
MLX_DIR = mlx
GNL_DIR = gnl
INCL_DIR = includes

# Source files, buildect files and headers (includes)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) $(GNL)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
INCLS = -I./$(INCL_DIR) -I./$(GNL_DIR)
SRC_FILES = \
		so_long.c \
		read_map.c \
		check_map.c \
		check_path.c \
		load_graphics.c \
		manage_errors.c \

# Get next line
GNL =	$(GNL_DIR)/get_next_line.c \
		$(GNL_DIR)/get_next_line_utils.c \

# Compiler, flags and library
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBRARY = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# General Rules
all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)/
	$(CC) $(CFLAGS) $(LIBRARY) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re