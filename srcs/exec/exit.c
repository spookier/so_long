/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:23:16 by acostin           #+#    #+#             */
/*   Updated: 2023/03/09 21:24:16 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	spawn_exit(t_all *all)
{
	if (all->exit_flag == 1 && all->map[(all->player_pos.y) / 32][(all->player_pos.x) / 32] == 'E')
	{
		//do ft_exit or something instead of exit
		exit(0);
	}
	return (0);
}

int	fill_exit(t_all *all)
{
	int	one;
	int	two;
	int	i;
	int	j;

	one = 0;
	two = 0;
	i = 0;
	while (two < MAP_HEIGHT)
	{
		j = 0;
		one = 0;
		while (one < MAP_WIDTH)
		{
			if (all->map[two][one] == 'E')
				mlx_put_image_to_window(all->engine.mlx,
					all->engine.mlx_win, all->sprites[3].texture_addr, j, i);
			j += 32;
			one++;
		}
		i += 32;
		two++;
	}
	spawn_exit(all);
	return (0);
}
