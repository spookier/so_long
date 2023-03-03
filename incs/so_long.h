#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

#include "unistd.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "../mlx_linux/mlx.h"

//SYSTEM
# define ESC		0xFF1B

// WINDOW
#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600
#define MAP_HEIGHT 10
#define MAP_WIDTH 10

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
	int x1;
	int y1;
}		t_pos2i;


typedef struct s_sprite {

	char	*texture_path;
	int		*texture_addr;
	int		texture_width;
	int		texture_height;
	int		texture_line_length;
	int		texture_bits_per_pixel;

}	t_sprite;

typedef struct s_player {

	char *texture_path;
	int pos_x;
	int pos_y;
} t_player;


typedef struct	s_all {

	t_engine	engine;
	t_sprite	sprites[8];
	t_pos2i		pos;
	
	int         **map;

}				t_all;


int		show_sprites(t_all *data);
int 	render(t_all *data);
int 	fill_player(t_all *all);
int 	fill_wall(t_all *all);
int 	fill_background(t_all *all);

#endif