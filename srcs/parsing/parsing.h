#ifndef GNL_SO_LONG_H
# define GNL_SO_LONG_H

#include "../../incs/so_long.h"

typedef struct s_pvars
{
	int		rows_map;
	int 	chars_map;
	char		**map;

} t_pvars;

void showmap(t_pvars *v);
int count_chars(char *line);
void free_map(t_pvars *v);
int alloc_map(t_pvars *v);
int fill_map(char *line, int fd, t_pvars *v);


int init_check_map(t_pvars *v);
#endif