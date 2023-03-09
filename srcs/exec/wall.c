/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:06:42 by acostin           #+#    #+#             */
/*   Updated: 2023/03/09 21:08:29 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	fill_wall(t_all *all)
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
			if (map[two][one] == 1)
				mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win,
					all->sprites[0].texture_addr, j, i);
			j += 32;
			one++;
		}
		i += 32;
		two++;
	}
	return (0);
}
