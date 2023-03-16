/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:24:22 by acostin           #+#    #+#             */
/*   Updated: 2023/03/16 09:00:33 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	fill_collectible_norminette(t_all *all, int *i, int *j)
{
	mlx_put_image_to_window(all->engine.mlx,
		all->engine.mlx_win, all->sprites[4].texture_addr, *j, *i);
	all->collectible_counter++;
}

int	fill_collectible(t_all *all)
{
	int	one;
	int	two;
	int	i;
	int	j;

	one = 0;
	two = 0;
	all->collectible_counter = 0;
	i = 0;
	while (two < all->map_height)
	{
		j = 0;
		one = 0;
		while (one < all->map_width)
		{
			if (all->map[two][one] == 'C')
				fill_collectible_norminette(all, &i, &j);
			j += 32;
			one++;
		}
		i += 32;
		two++;
	}
	return (0);
}

int	eat_collectible(t_all *all)
{
	all->map[all->player_pos.y / 32][all->player_pos.x / 32] = '0';
	if (all->collectible_counter - 1 == 0)
		all->exit_flag = 1;
	all->collectible_counter--;
	return (0);
}

int	check_collectible(t_all *all)
{
	if (all->map[all->player_pos.y / 32][all->player_pos.x / 32] == 'C')
		eat_collectible(all);
	return (0);
}
