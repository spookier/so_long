#ifndef GNL_SO_LONG_H
# define GNL_SO_LONG_H

#include "../../incs/so_long.h"

typedef struct s_pvars
{
	int		rows_map;
	int 	chars_map;
	char		**map;

} t_pvars;

typedef struct s_items
{
	int start;
	int exit;
	int collectibles;

} t_items;

typedef struct s_pall
{
	t_pvars vars;
	t_items items;

}	t_pall;

void showmap(t_pvars *v);
int count_chars(char *line);
void free_map(t_pvars *v);
int alloc_map(t_pvars *v);
int fill_map(char *line, int fd, t_pvars *v);


int init_check_map(t_pall *all);
#endif