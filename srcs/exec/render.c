/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:08:36 by acostin           #+#    #+#             */
/*   Updated: 2023/03/14 08:44:48 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	*sprite_loader(t_all *all, char *texture_path)
{
	int	*texture;
	int	zero;

	zero = 0;
	texture = NULL;
	texture = mlx_xpm_file_to_image(all->engine.mlx,
			texture_path, &zero, &zero);
	if (!texture)
	{
		printf("Error\nFailed to load texture\n");
		return (NULL);
	}
	return (texture);
}

static int	load_sprites(t_all *all)
{
	//check if sprite is NULL return 1
	all->sprites[0].texture_addr = sprite_loader(all, "textures/block_.xpm");
	all->sprites[1].texture_addr = sprite_loader(all, "textures/player_.xpm");
	all->sprites[2].texture_addr = sprite_loader(all, "textures/sand_.xpm");
	all->sprites[3].texture_addr = sprite_loader(all, "textures/exit_.xpm");
	all->sprites[4].texture_addr = sprite_loader(all, "textures/collectible_.xpm");
	return (0);
}

int	show_sprites(t_all *data)
{
	load_sprites(data);
	data->exit_flag = 0;
	data->move_counter = 0;
	fill_background(data);
	fill_wall(data);
	fill_collectible(data);
	spawn_player(data);
	return (0);
}

int	redraw(t_all *data)
{
	fill_background(data);
	fill_wall(data);
	fill_collectible(data);
	return (0);
}
