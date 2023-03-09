/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:20:46 by acostin           #+#    #+#             */
/*   Updated: 2023/03/09 21:21:09 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	move_player_up(t_all *all)
{
	if (map[(all->player_pos.y - 32) / 32][(all->player_pos.x) / 32] != 1)
	{
		all->player_pos.y -= 32;
		update_player(all);
	}
	return (0);
}

int	move_player_down(t_all *all)
{
	if (map[(all->player_pos.y + 32) / 32][(all->player_pos.x) / 32] != 1)
	{
		all->player_pos.y += 32;
		update_player(all);
	}
	return (0);
}

int	move_player_left(t_all *all)
{
	if (map[(all->player_pos.y) / 32][(all->player_pos.x - 32) / 32] != 1)
	{
		all->player_pos.x -= 32;
		update_player(all);
	}
	return (0);
}

int	move_player_right(t_all *all)
{
	if (map[(all->player_pos.y) / 32][(all->player_pos.x + 32) / 32] != 1)
	{
		all->player_pos.x += 32;
		update_player(all);
	}
	return (0);
}
