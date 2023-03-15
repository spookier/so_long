/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:41:36 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 23:53:51 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	check_rectangle(t_pall *all)
{
	int	expected_cols;
	int	i;

	i = 0;
	expected_cols = all->vars.chars_map;
	while (i < all->vars.rows_map)
	{
		if ((int)ft_strlen(all->vars.map[i]) != expected_cols)
		{
			all->error = "Error\nMap is not rectangular\n";
			return (1);
		}
		expected_cols = ft_strlen(all->vars.map[i]);
		i++;
	}
	return (0);
}

static int	check_map_validity(t_pall *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->vars.rows_map)
	{
		j = 0;
		while (j < all->vars.chars_map)
		{
			if (all->vars.map[i][j] == 'E')
				all->items.exit++;
			else if (all->vars.map[i][j] == 'C')
				all->items.collectibles++;
			else if (all->vars.map[i][j] == 'P')
				all->items.start++;
			else if (all->vars.map[i][j] != '0' && all->vars.map[i][j] != '1')
			{
				all->error = "Error\nInvalid character in map\n";
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	init_items(t_pall *all)
{
	all->items.start = 0;
	all->items.exit = 0;
	all->items.collectibles = 0;
	if (check_map_validity(all) == 1)
		return (1);
	if (all->items.start != 1 || all->items.exit != 1
		|| all->items.collectibles < 1)
	{
		all->error = "Error\nNot enough map components\n";
		return (1);
	}
	return (0);
}

int	error_check(t_pall *all)
{
	all->items.exit_found = 0;
	if (all->vars.rows_map < 3 || all->vars.chars_map < 2)
	{
		all->error = "Error\nInvalid map\n";
		return (1);
	}
	if (check_rectangle(all) == 1 || init_items(all) == 1)
		return (1);
	if (check_walls_surround(&all->vars) == 1)
	{
		all->error = "Error\nMap not surrounded by walls\n";
		return (1);
	}
	return (0);
}
