
#include "../../incs/so_long.h"

typedef struct s_gnl_vars
{
	int count;
	int length;
	char	**map;

} t_gnl_vars;

int count_chars(char *line)
{
	int chars;

	chars = 0;
	chars = ft_strlen(line);
	return (chars);
}

int check_rectangle(int fd, char *line, t_gnl_vars *vars)
{
	if (vars->count == 1)
		vars->length = count_chars(line);
	else
	{
		if (vars->length != count_chars(line))
		{
			ft_printf("Error\nMap is not a rectangle\n");
			free(line);
			while (1)
			{
				line = get_next_line(fd);
				if (line == NULL)
					break;
				free(line);
			}
			close(fd);
			exit(1);
		}
	}
	return (vars->length);
}

int check_walls(int fd, char *line, t_gnl_vars *vars)
{
	if (vars->count == 1)
	{
		int i = 0;
		while (line[i])
		{
			if (line[i] != '1')
			{
				ft_printf("Error\nInvalid map\n");
				free(line);
				while (1)
				{
					line = get_next_line(fd);
					if (line == NULL)
						break;
					free(line);
				}
				close(fd);
				exit(1);
			}
			i++;
		}
	}
	return (0);
}

int check_borders(int fd, char *line, t_gnl_vars *vars)
{
	if (line[0] == '1' && line[vars->length - 1] == '1')
		return (0);
	else
	{
		ft_printf("Error\nInvalid map borders\n");
		free(line);
		while (1)
		{
			line = get_next_line(fd);
			if (line == NULL)
				break;
			free(line);
		}
		close(fd);
		exit(1);
	}
}


void check_functions(int fd, char *line, t_gnl_vars *vars)
{
	vars->length = check_rectangle(fd, line, vars);
	check_walls(fd, line, vars);
	check_borders(fd, line, vars);
	free(line);
}


int	alloc_map(int fd, char *line, t_gnl_vars *v)
{
	int i;

	i = 0;
	v->map = NULL;
	v->map = (char **)malloc(sizeof(char*) * v->count);
	if(v->map == NULL)
		return(1);
}

void check_line(int fd, char *line, t_gnl_vars *vars)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (*line == '\n' || *line == '#')
		{
			free(line);
			continue;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		vars->count += 1;
		check_functions(fd, line, vars);
	}
	alloc_map(fd, line, vars);
}

int check_arg(char *argv)
{
	int len;

	len = ft_strlen(argv);
	if (len <= 4)
	{
		ft_printf("Error\nNot a .ber type\n");

		return (1);
	}
	if (ft_strcmp(argv + len - 4, ".ber") != 0)
	{
		ft_printf("Error\nNot a .ber type\n");
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	int fd;
	char *line;
	t_gnl_vars vars;
	//char **map;

	if (argc != 2)
		return (1);
	vars.length = 0;
	vars.count = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);

	check_arg(argv[1]);

	check_line(fd, line, &vars);

	close(fd);
	return (0);
}