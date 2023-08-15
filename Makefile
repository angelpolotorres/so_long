
# Final program ---------------------------------------------- #
# ------------------------------------------------------------ #
NAME = so_long

# Source files ----------------------------------------------- #
# ------------------------------------------------------------ #
SRCS = $(SRC_FILES) $(SRC_GNL_FILES)

SRC_DIR = src
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC_CFILES))
SRC_CFILES = \
		so_long.c \
		read_map.c \
		check_map.c \
		check_path.c \
		load_graphics.c \
		manage_errors.c \
		controls.c \
		show_score.c \

SRC_GNL_DIR = $(SRC_DIR)/gnl
SRC_GNL_FILES = $(addprefix $(SRC_GNL_DIR)/, $(SRC_GNL_CFILES))
SRC_GNL_CFILES = \
		get_next_line.c \
		get_next_line_utils.c \

MLX_DIR = $(SRC_DIR)/mlx

# Object files ----------------------------------------------- #
# ------------------------------------------------------------ #
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

OBJ_DIR = build
OBJ_GNL_DIR = $(OBJ_DIR)/gnl

# Compiler options ------------------------------------------- #
# ------------------------------------------------------------ #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS := -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCL_DIR := includes

# Rules ------------------------------------------------------ #
# ------------------------------------------------------------ #
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(OBJ_GNL_DIR) 
	$(CC) $(CFLAGS) -I./$(INCL_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_GNL_DIR):
	mkdir -p $(OBJ_GNL_DIR)

clean:
	rm -rf $(OBJ_DIR)
#	$(MAKE) -C $(MLX_DIR) clean 
#	Activar si quieres eliminar los .o de mlx con el clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re