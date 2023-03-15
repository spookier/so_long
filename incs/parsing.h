/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:26:18 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 23:57:48 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "so_long.h"

void	showmap(t_pvars *v);
int		count_chars(char *line);
void	free_map(t_pvars *v);
int		alloc_map(t_pvars *v);
int		fill_map(char *line, int fd, t_pvars *v);

int		check_walls_surround(t_pvars *v);

int		error_check(t_pall *all);

int		flood_fill(t_pall *all, char **visited, t_point cur);

int		init_check_map(t_pall *all);

int		parsing_main(t_pall *all, int argc, char **argv);

#endif
