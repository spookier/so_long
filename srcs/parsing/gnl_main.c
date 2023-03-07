// #include "../../libft/incs/get_next_line.h"
// #include "../../libft/incs/libft.h"
// #include "../../libft/incs/ft_printf.h"
// #include <fcntl.h>
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
			printf("Error\n");
			free(line);
			close(fd);
			return (1);
		}
	}
	return(length);
}


void check_line(int fd, char *line)
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
		printf("line = %s\n", line);
	}
		printf("end of check line\n");

}


int check_arg(char *argv)
{
	int len;

	len = ft_strlen(argv);
	if (len <= 4)
	{
		ft_printf("File extension error. Not a .ber type\n");
		return (1);
	}
	if (ft_strcmp(argv + len - 4, ".ber") != 0)
	{
    	ft_printf("File extension error. Not a .ber type\n");
    	return 1;
	}
	printf("end of check arg\n");
	return(0);
}


int main(int argc, char **argv)
{
	int fd;
	char *line;

	if(argc != 2)
		return(1);

	line = NULL;
	fd = open("test.txt", O_RDONLY);

	check_arg(argv[1]);

	check_line(fd, line);

	ft_printf("end of gnl\n");

	
	close(fd);
	return(0);
}
