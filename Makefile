
# Variables
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

# path for srcs
SRCS_DIR = ./srcs/
SRCS_UTILS_DIR = ./srcs/utils/

#path for LIBFT
LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

# path for header
INCS_DIR = ./incs

# path for MLX
MLX_DIR = ./mlx_linux
MLX_FLAGS = -lX11 -lXext -lm
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)


# Mandatory files
FILES =		$(SRCS_DIR)exec/wall.c \
			$(SRCS_DIR)exec/render.c \
			$(SRCS_DIR)exec/player.c \
			$(SRCS_DIR)exec/player_move.c \
			$(SRCS_DIR)exec/background.c \
			$(SRCS_DIR)exec/exit.c \
			$(SRCS_DIR)exec/collectible.c \
			$(SRCS_DIR)exec/exec_main.c \
			$(SRCS_DIR)parsing/parsing_check.c \
			$(SRCS_DIR)parsing/parsing_error_check_1.c \
			$(SRCS_DIR)parsing/parsing_error_check_2.c \
			$(SRCS_DIR)parsing/parsing_flood_fill.c \
			$(SRCS_DIR)parsing/parsing_functions.c \
			$(SRCS_DIR)parsing/parsing_main.c \
			$(SRCS_DIR)main.c \


# Transform .c files into .o
OBJ_FILES = $(FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)


all : $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)


$(NAME) : $(MLX) $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)


$(MLX):
	make -C $(MLX_DIR)


# Clean all object files created
clean : 
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_FILES)
	make clean -C $(MLX_DIR)

# Clean all object files + the library created
fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

#Fclean then build all
re : fclean
	make all

.PHONY : all clean fclean re
