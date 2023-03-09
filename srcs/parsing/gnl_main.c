#include "../../incs/so_long.h"

int count_chars(char *line)
{
	int chars;

	chars = 0;
	chars = ft_strlen(line);
	return (chars);
}

int check_rectangle(int fd, char *line, int count, int length)
{
	if (count == 1)
		length = count_chars(line);
	else
	{
		if (length != count_chars(line))
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
			printf("exit\n");
			exit(1);
		}
	}
	return (length);
}

int check_walls(int fd, char *line, int count)
{
	if (count == 1 || count == -1)
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

int check_borders(int fd, char *line, int length)
{
	if (line[0] == '1' && line[length - 1] == '1')
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

void check_line(int fd, char *line)
{
	int length;
	int count;
	char *last_line;

	length = 0;
	count = 0;

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
		count++;
		length = check_rectangle(fd, line, count, length);
		check_walls(fd, line, count);
		check_borders(fd, line, length);
		last_line = ft_strdup(line);
		free(line);
	}
	check_walls(fd, last_line, -1);
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

	if (argc != 2)
		return (1);

	line = NULL;
	fd = open(argv[1], O_RDONLY);

	check_arg(argv[1]);

	check_line(fd, line);

	// ft_printf("-----------end of gnl-----------\n");

	close(fd);
	return (0);
}