#include "parsing.h"


void showmap(t_pvars *v)
{
	int i;

	i = 0;
	while (i < v->rows_map)
	{
		printf("map[%d] = %s\n", i, v->map[i]);
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


int fill_map(char *line, int fd, t_pvars *v)
{
	int i;
	i = 0;
	while (i < v->rows_map)
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

		ft_strlcpy(v->map[i], line, v->chars_map);
		free(line);
		i++;
	}
	get_next_line(-1);
	printf("map fill'd\n");
	return (0);
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
	printf("map free'd\n");
}


int alloc_map(t_pvars *v)
{
	int i;

	i = 0;
	v->map = NULL;
	v->map = (char **)malloc(v->rows_map * sizeof(char *));
	if (v->map == NULL)
		return (1);
	while (i < v->rows_map)
	{
		v->map[i] = (char *)malloc(sizeof(char) * (v->chars_map + 1));
		if (v->map[i] == NULL)
		{
			// free
			while (i)
			{
				free(v->map[i - 1]);
				i--;
			}
			free(v->map);
			return (1);
		}
		i++;
	}
	printf("map alloc'd\n");
	return (0);
}