#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/incs/get_next_line.h"
#include "../libft/incs/libft.h"
#include "../libft/incs/ft_printf.h"
#include "../mlx_linux/mlx.h"
#include "./keycodes.h"

//SYSTEM
# define ESC		0xFF1B

// WINDOW
#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1080
#define MAP_HEIGHT 30
#define MAP_WIDTH 30

#define TILE_SIZE 32

extern int map[MAP_HEIGHT][MAP_WIDTH];

//STRUCTS
typedef struct	s_engine {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		*img_addr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	void 	*params;
}				t_engine;



typedef struct s_pos2i {
	int x;
	int y;
}		t_pos2i;


typedef struct s_sprite {

	char	*texture_path;
	int		*texture_addr;
	int		texture_width;
	int		texture_height;
	int		texture_line_length;
	int		texture_bits_per_pixel;

}	t_sprite;


typedef struct	s_all {

	t_engine	engine;
	t_sprite	sprites[8];
	t_pos2i		player_pos;
	int 		move_counter;
	int			collectible_counter;
	int			exit_flag;
	int         **map;

}				t_all;




int		key_hook(int keycode, t_all *all);

int		show_sprites(t_all *data);
int		redraw(t_all *data);

int 	spawn_player(t_all *all);
int		update_player(t_all *data);

int	move_player_up(t_all *all);
int	move_player_down(t_all *all);
int	move_player_left(t_all *all);
int	move_player_right(t_all *all);

int 	fill_wall(t_all *all);
int 	fill_background(t_all *all);
int 	fill_exit(t_all *all);
int 	fill_collectible(t_all *all);

int 	check_collectible(t_all *all);


//PARSING FUNCTIONS


#endif
