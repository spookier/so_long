#include "gnl_so_long.h"


void showmap(t_pvars *v)
{
	int i;

	i = 0;
	while(i < v->rows_map)
	{
		printf("[%d] = %s\n", i, v->map[i]);
		i++;
	}
}

int count_chars(char *line)
{
	int chars;

	chars = 0;
	chars = ft_strlen(line);
	return (chars);
}


int fill_map(int fd, t_pvars *v)
{
	int i;
	char *line;
	i = 0;
	line = NULL;
	while(i < v->rows_map)
	{
		printf("entered loop !!\n");
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
		v->map[i] = line;
		i++;
		free(line);
	}
	printf("map filled\n");
	return(0);
}



void free_map(t_pvars *v)
{
	int i;

    if (v->map != NULL) 
	{
		i = 0;
        while (i < v->rows_map) 
		{
            free(v->map[i]);
            i++;
        }
        free(v->map);
        v->map = NULL;
    }
	printf("map freed\n");
}


int alloc_map(t_pvars *v)
{
	int i;

	i = 0;
	v->map = NULL;
	v->map = (char **)malloc(v->rows_map * sizeof(char *));
	if(v->map == NULL)
		return(1);
	while(i < v->rows_map)
	{
		v->map[i] = (char*)malloc(sizeof(char) * (v->chars_map + 1));
		if(v->map[i] == NULL)
			return(1);
		i++;
	}
	printf("map alloc'd\n");
	return(0);
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
		printf("line = %s\n", line);
		free(line);
	}
	printf("size is rows:%d | chars:%d\n", v->rows_map, v->chars_map);
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
	if(fd < 0)
		return(1);
		
	//--exec
	calculate_map_size(line, fd, v);
	if(alloc_map(v) == 1)
		return(1);
	free_map(v);

	fill_map(fd, v);
	//showmap(v);

	//--cleanup	
	free_map(v);
	close(fd);
	return(0);
}


int main(int argc, char **argv)
{

	t_pvars vars;
	
	if (argc != 2)
		return (1);
	check_arg(argv[1]);
	parsing_exec(argv[1], &vars);



	printf("--------------end of parsing--------------\n");
	return (0);
}

