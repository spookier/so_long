/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:53:14 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 23:54:10 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	check_walls_surround_norminette(t_pvars *v, int *i)
{
	while (*i < v->rows_map)
	{
		if (v->map[*i][0] == '1' && v->map[*i][v->chars_map - 1] == '1')
			(*i)++;
		else
			return (1);
	}
	return (0);
}

int	check_walls_surround(t_pvars *v)
{
	int	i;

	i = 0;
	while (v->map[0][i])
	{
		if (v->map[0][i] == '1')
			i++;
		else
			return (1);
	}
	i = 0;
	while (v->map[v->rows_map - 1][i])
	{
		if (v->map[v->rows_map - 1][i] == '1')
			i++;
		else
			return (1);
	}
	i = 0;
	if (check_walls_surround_norminette(v, &i))
		return (1);
	return (0);
}
