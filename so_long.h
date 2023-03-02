#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

#include "unistd.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "mlx_linux/mlx.h"

//COLORS
# define WHITE 		0xFFFFFF
# define RED 		0xFF0000

//SYSTEM
# define ESC		0xFF1B

typedef int				t_v2i __attribute__((vector_size (8)));


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


typedef struct	s_all {

	t_engine	engine;
	t_sprite	sprites[8];
	t_pos2i		pos;
	
	int         **map;

}				t_all;




#endif