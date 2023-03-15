/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:48:24 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 23:51:29 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	calculate_map_size(char *argv, char *line, int fd, t_pvars *v)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (*line == '\n' || *line == '#')
		{
			free(line);
			continue ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		v->rows_map += 1;
		v->chars_map = count_chars(line);
		free(line);
	}
	get_next_line(-1);
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}

int	check_arg(t_pall *all, int argc, char *argv)
{
	int	len;

	if (argc != 2)
	{
		all->error = "Error\nArgument error\n";
		return (1);
	}
	len = ft_strlen(argv);
	if (len <= 4)
	{
		all->error = "Error\nNot a .ber type\n";
		return (1);
	}
	if (ft_strcmp(argv + len - 4, ".ber") != 0)
	{
		all->error = "Error\nNot a .ber type\n";
		return (1);
	}
	return (0);
}

static int	parsing_exec_norminette(t_pall *all, int fd)
{
	if (fd < 0)
	{
		all->error = "Error\nFile not found\n";
		return (1);
	}
	return (0);
}

int	parsing_exec(char *argv, t_pall *all)
{
	int		fd;
	char	*line;

	all->vars.rows_map = 0;
	all->vars.chars_map = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	if (parsing_exec_norminette(all, fd))
		return (1);
	if (calculate_map_size(argv, line, fd, &all->vars) == 1
		|| alloc_map(&all->vars) == 1)
	{
		all->error = "Error\nFailed to allocate map\n";
		return (1);
	}
	fill_map(line, fd, &all->vars);
	if (init_check_map(all) == 1)
	{
		free_map(&all->vars);
		return (1);
	}
	close(fd);
	return (0);
}

int	parsing_main(t_pall *all, int argc, char **argv)
{
	all->error = NULL;
	if (check_arg(all, argc, argv[1]) == 1 || parsing_exec(argv[1], all) == 1)
	{
		ft_printf("%s", all->error);
		return (1);
	}
	ft_printf("--------------PARSING OK--------------\n");
	return (0);
}
