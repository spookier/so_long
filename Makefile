
# Variables
NAME = so_long
CC = cc
# CFLAGS = -Wall -Wextra -Werror

# path for srcs
SRCS_DIR = ./srcs/
SRCS_UTILS_DIR = ./srcs/utils/


# path for header
INCS_DIR = ./incs

# path for MLX
MLX_DIR = ./mlx_linux
MLX_FLAGS = -lX11 -lXext -lm
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)


# Mandatory files
FILES =		$(SRCS_DIR)wall.c \
			$(SRCS_DIR)render.c \
			$(SRCS_DIR)player.c \
			$(SRCS_DIR)background.c \
			$(SRCS_DIR)exit.c \
			$(SRCS_DIR)collectible.c \
			$(SRCS_DIR)main.c \
			

# Transform .c files into .o
OBJ_FILES = $(FILES:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCS_DIR)


all : $(NAME)


$(NAME) : $(MLX) $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ -I$(INCS_DIR) -L$(MLX_DIR) -lmlx $(MLX_FLAGS)


$(MLX):
	make -C $(MLX_DIR)


# Clean all object files created
clean : 
	rm -rf $(OBJ_FILES)
	make clean -C $(MLX_DIR)

# Clean all object files + the library created
fclean : clean
	rm -rf $(NAME)


#Fclean then build all
re : fclean
	make all

ex :
	make all && ./so_long


.PHONY : all clean fclean re