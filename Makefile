MLX_FLAGS= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm
COMPILER=cc


ex:
	$(COMPILER) -I mlx_linux so_long.c -g3 $(MLX_FLAGS) && ./a.out 

clean:
	rm -rf a.out