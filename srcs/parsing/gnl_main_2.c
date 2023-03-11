#include "gnl_so_long.h"

int count_chars(char *line)
{
	int chars;

	chars = 0;
	chars = ft_strlen(line);
	return (chars);
}


int alloc_map(t_pvars *v)
{
	int i;

	i = 0;
	v->map = NULL;
	v->map = (int **)malloc(v->rows_map * sizeof(int *));
	if(v->map == NULL)
		return(1);
	while(i <= v->rows_map)
	{
		v->map[i] = (int*)malloc(sizeof(int*));
	}
}

void calculate_map_size(char *line, int fd, t_pvars *v)
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
		v->rows_map += 1;
		v->chars_map = count_chars(line);
		free(line);
	}
	printf("size is %dx%d\n", v->rows_map, v->chars_map);
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
	t_pvars vars;

	if (argc != 2)
		return (1);

	vars.rows_map = 0;
	vars.chars_map = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	check_arg(argv[1]);

	calculate_map_size(line, fd, &vars);
	
	printf("--------------end of parsing--------------\n");

	//check_line(fd, line, &vars);
	close(fd);
	return (0);
}

