/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flood_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:43:33 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 23:44:50 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static void	fill(t_pall *all, char **visited, t_point cur)
{
	if (cur.y < 0 || cur.y >= all->vars.rows_map
		|| cur.x < 0 || cur.x >= all->vars.chars_map
		|| visited[cur.y][cur.x] == 'x' || visited[cur.y][cur.x] == '1')
		return ;
	if (visited[cur.y][cur.x] == 'E')
		all->items.exit_found = 1;
	if (visited[cur.y][cur.x] == 'C')
		all->items.check_collectibles--;
	visited[cur.y][cur.x] = 'x';
	fill(all, visited, (t_point){cur.x - 1, cur.y});
	fill(all, visited, (t_point){cur.x + 1, cur.y});
	fill(all, visited, (t_point){cur.x, cur.y - 1});
	fill(all, visited, (t_point){cur.x, cur.y + 1});
}

int	flood_fill(t_pall *all, char **visited, t_point cur)
{
	fill(all, visited, cur);
	ft_printf("collectibles: %d\n", all->items.check_collectibles);
	ft_printf("exit: %d\n", all->items.exit_found);
	if (all->items.exit_found == 1 && all->items.check_collectibles == 0)
	{
		ft_printf("MAP FOUND!!!!!!!!!\n");
		return (0);
	}
	else
		return (1);
}
