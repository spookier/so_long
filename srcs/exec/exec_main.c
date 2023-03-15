/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:46:27 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 22:55:36 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	mlx_start(t_all *data)
{
	ft_printf("MLX START!\n");
	data->engine.mlx
		= mlx_init();
	data->engine.mlx_win
		= mlx_new_window(data->engine.mlx, data->screen_height,
			data->screen_width, "so long!");
	data->engine.img
		= mlx_new_image(data->engine.mlx,
			data->screen_height, data->screen_width);
	data->engine.addr
		= mlx_get_data_addr(data->engine.img, &data->engine.bits_per_pixel,
			&data->engine.line_length, &data->engine.endian);
}

int	ft_exit(t_all *all)
{
	free_and_exit(all);
	return (0);
}

void	find_map_size(t_all *data, t_pall *parsing)
{
	int	map_width_px;
	int	map_height_px;

	data->map_width = parsing->vars.chars_map;
	data->map_height = parsing->vars.rows_map;
	map_width_px = parsing->vars.rows_map * TILE_SIZE;
	map_height_px = parsing->vars.chars_map * TILE_SIZE;
	data->screen_width = map_width_px;
	data->screen_height = map_height_px;
}

int	exec_main(t_pall *p)
{
	t_all	data;

	data.check_exit_esc = 0;
	data.map = p->vars.map;
	find_map_size(&data, p);
	mlx_start(&data);
	show_sprites(&data);
	mlx_key_hook(data.engine.mlx_win, key_hook, &data.engine);
	mlx_hook(data.engine.mlx_win, 17, 2, ft_exit, &data.engine);
	mlx_loop(data.engine.mlx);
	return (0);
}
