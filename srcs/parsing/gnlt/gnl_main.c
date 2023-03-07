#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>


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
			printf("error\n");
			free(line);
			close(fd);
			return (1);
		}
	}
	return(length);
}

void check_gnl(int fd, char *line)
{
	int length;
	int count;

	length = 0;
	count = 0;
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
		count++;
		length = check_rectangle(fd, line, count, length);
	}
}


int main(void)
{
	int fd;
	char *line;

	line = NULL;
	fd = open("test.txt", O_RDONLY);

	check_gnl(fd, line);

	close(fd);
	return(0);
}

// int main(void)
// {
// 	int fd;
// 	char *line;
// 	int	length;
// 	int	count;

// 	line = NULL;
// 	fd = open("test.txt", O_RDONLY);

// 	length = 0;
// 	count = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		if (*line == '\n' || *line == '#')
// 		{
// 			free(line);
// 			continue ;
// 		}
// 		if (line[ft_strlen(line) - 1] == '\n')
// 			line[ft_strlen(line) - 1] = '\0';
// 		count++;
// 		length = check_rectangle(fd, line, count, length);
// 		//if (err)
// 		//	finish_gnl(scene, &line, fd, err);
// 	}
// 	close(fd);
// 	return(0);
// }
