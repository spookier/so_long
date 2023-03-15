/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:57:13 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 23:58:03 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	find_player(t_pall *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->vars.rows_map)
	{
		j = 0;
		while (j < all->vars.chars_map)
		{
			if (all->vars.map[i][j] == 'P')
			{
				all->items.pos_start_x = j;
				all->items.pos_start_y = i;
			}
			j++;
		}
		i++;
	}
	ft_printf("found player @ x=%d y=%d\n",
		all->items.pos_start_x, all->items.pos_start_y);
	return ;
}

static void	copy_map(t_pall *all, char **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->vars.rows_map)
	{
		j = 0;
		while (j < all->vars.chars_map)
		{
			visited[i][j] = all->vars.map[i][j];
			j++;
		}
		i++;
	}
	return ;
}

static void	alloc_map_for_flood_fill(t_pall *all, char **visited)
{
	int	i;

	i = 0;
	while (i < all->vars.rows_map)
	{
		visited[i] = (char *)ft_calloc(sizeof(char), all->vars.chars_map + 1);
		i++;
	}
}

static void	free_map_for_flood_fill(t_pall *all, char **visited)
{
	int	i;

	i = 0;
	while (i < all->vars.rows_map)
		free(visited[i++]);
	free(visited);
}

int	init_check_map(t_pall *all)
{
	t_point	cur;
	char	**visited;

	visited = (char **)ft_calloc(sizeof(char *), all->vars.rows_map + 1);
	alloc_map_for_flood_fill(all, visited);
	if (error_check(all))
	{
		free_map_for_flood_fill(all, visited);
		return (1);
	}
	copy_map(all, visited);
	find_player(all);
	all->items.check_collectibles = all->items.collectibles;
	cur.x = all->items.pos_start_x;
	cur.y = all->items.pos_start_y;
	ft_printf("START COLLECTIBLES = %d\n", all->items.check_collectibles);
	if (flood_fill(all, visited, cur) == 1)
	{
		all->error = "Error\nPath not found\n";
		return (1);
	}
	ft_printf("map checked\n");
	free_map_for_flood_fill(all, visited);
	return (0);
}
