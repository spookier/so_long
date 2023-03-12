#include "parsing.h"

int calculate_map_size(char *argv, char *line, int fd, t_pvars *v)
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
	get_next_line(-1);
	close(fd);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
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


int parsing_exec(char *argv, t_pvars *v)
{
	int fd;
	char *line;

	v->rows_map = 0;
	v->chars_map = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);

	//--exec
	if (calculate_map_size(argv, line, fd, v) == 1 || alloc_map(v) == 1)
		return (1);
	fill_map(line, fd, v);
	
	if(init_check_map(v) == 1)
	{
		free_map(v);
		return(1);
	}
	

	showmap(v);


	//--cleanup
	free_map(v);
	close(fd);
	return (0);
}

int main(int argc, char **argv)
{
	t_pvars vars;

	if (argc != 2)
		return (1);
	check_arg(argv[1]);
	if (parsing_exec(argv[1], &vars) == 1)
	{
		printf("++Error\n++Parsing failed\n");
		return (1);
	}
	printf("--------------end of parsing--------------\n");
	return (0);
}
