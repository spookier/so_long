#ifndef PARSING_H
# define PARSING_H

#include "so_long.h"



void showmap(t_pvars *v);
int count_chars(char *line);
void free_map(t_pvars *v);
int alloc_map(t_pvars *v);
int fill_map(char *line, int fd, t_pvars *v);


int init_check_map(t_pall *all);

int parsing_main(t_pall *all, int argc, char **argv);

#endif