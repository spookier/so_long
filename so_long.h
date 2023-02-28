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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	void 	*params;
}				t_engine;



typedef struct s_pos2i {
	int x;
	int y;
	int x1;
	int y1;
}		t_pos2i;


typedef struct s_sprite {

	void	*sprite;
	char	*relative_path;
	int		width;
	int		height;

}	t_sprite;


typedef struct	s_all {

	t_engine	engine;
	t_sprite	sprites[8];
	t_pos2i		pos;

}				t_all;




#endif