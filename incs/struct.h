/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:26:54 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 22:35:34 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "so_long.h"

typedef struct s_engine {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			*img_addr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_width;
	int			img_height;
	void		*params;

}	t_engine;

typedef struct s_pos2i {
	int			x;
	int			y;
}	t_pos2i;

typedef struct s_sprite {
	char		*texture_path;
	int			*texture_addr;
	int			texture_width;
	int			texture_height;
	int			texture_line_length;
	int			texture_bits_per_pixel;

}	t_sprite;

typedef struct s_all {
	t_engine	engine;
	t_sprite	sprites[8];
	t_pos2i		player_pos;
	int			move_counter;
	int			collectible_counter;
	int			exit_flag;
	char		**map;
	int			screen_height;
	int			screen_width;
	int			map_height;
	int			map_width;
	int			check_exit_esc;

}	t_all;

typedef struct s_pvars
{
	int			rows_map;
	int			chars_map;
	char		**map;

}	t_pvars;

typedef struct s_items
{
	int			start;
	int			exit;
	int			collectibles;
	int			pos_start_x;
	int			pos_start_y;
	int			check_collectibles;
	int			exit_found;

}	t_items;

typedef struct s_point
{
	int				x;
	int				y;
}	t_point;

typedef struct s_pall
{
	t_pvars		vars;
	t_items		items;
	t_point		point;
	char		*error;

}	t_pall;

#endif
