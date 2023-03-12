#include "parsing.h"




int init_check_map(t_pvars *v)
{
	if(v->rows_map < 3 || v->chars_map < 2)
	{
		ft_printf("Error\nInvalid map\n");
		return(1);
	}

	printf("map checked\n");
	return(0);
}