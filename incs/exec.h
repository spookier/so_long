/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:22:22 by acostin           #+#    #+#             */
/*   Updated: 2023/03/16 09:39:58 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/incs/get_next_line.h"
# include "../libft/incs/libft.h"
# include "../libft/incs/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include "so_long.h"

# define TILE_SIZE 32

//MAIN FUNCTIONS
int		exec_main(t_pall *p);
void	free_and_exit(t_all *all);
void	free_if_sprites_exist(t_all *all);

int		key_hook(int keycode, t_all *all);

int		show_sprites(t_all *data);
int		redraw(t_all *data);

int		spawn_player(t_all *all);
int		update_player(t_all *data);

int		move_player_up(t_all *all);
int		move_player_down(t_all *all);
int		move_player_left(t_all *all);
int		move_player_right(t_all *all);

int		fill_wall(t_all *all);
int		fill_background(t_all *all);
int		fill_exit(t_all *all);
int		fill_collectible(t_all *all);

int		check_collectible(t_all *all);

#endif
