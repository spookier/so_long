/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:10:54 by acostin           #+#    #+#             */
/*   Updated: 2023/03/11 03:00:58 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	spawn_player_norminette(t_all *all, int i, int j)
{
	mlx_put_image_to_window(all->engine.mlx,
		all->engine.mlx_win, all->sprites[1].texture_addr, j, i);
	all->player_pos.y = i;
	all->player_pos.x = j;
}

int	spawn_player(t_all *all)
{
	int	map_xy[2];
	int	i;
	int	j;

	map_xy[0] = 0;
	map_xy[1] = 0;
	i = 0;
	while (map_xy[1] < all->MAP_HEIGHT)
	{
		j = 0;
		map_xy[0] = 0;
		while (map_xy[0] < all->MAP_WIDTH)
		{
			if (all->map[map_xy[1]][map_xy[0]] == 'P')
				spawn_player_norminette(all, i, j);
			j += 32;
			map_xy[0]++;
		}
		i += 32;
		map_xy[1]++;
	}
	ft_printf("moves: %d\n", all->move_counter);
	return (0);
}

int	update_player(t_all *all)
{
	check_collectible(all);
	redraw(all);
	if (all->exit_flag == 1)
		fill_exit(all);
	mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win,
		all->sprites[1].texture_addr, all->player_pos.x, all->player_pos.y);
	all->move_counter++;
	printf("moves: %d\n", all->move_counter);
	return (0);
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_W)
		move_player_up(all);
	if (keycode == KEY_S)
		move_player_down(all);
	if (keycode == KEY_A)
		move_player_left(all);
	if (keycode == KEY_D)
		move_player_right(all);
	if (keycode == ESC)
	{
		mlx_clear_window(all->engine.mlx, all->engine.mlx_win);
		mlx_destroy_window(all->engine.mlx, all->engine.mlx_win);
		/* don't  forget to free everything */
		exit(1);
	}
	return (0);
}
