#include "parsing.h"

static int check_rectangle(t_pvars *v)
{
  	int expected_cols;
	int i;

    i = 0;
	expected_cols = v->chars_map;
    while (i < v->rows_map) 
	{
        if ((int)ft_strlen(v->map[i]) != expected_cols) 
		{
            printf("Error\nMap is not rectangular\n");
            return (1);
        }
        expected_cols = ft_strlen(v->map[i]);
        i++;
    }
    return 0;
}

int init_check_map(t_pvars *v)
{

	if(v->rows_map < 3 || v->chars_map < 2)
	{
		ft_printf("Error\nInvalid map\n");
		return(1);
	}

	if(check_rectangle(v) == 1)
		return(1);

	printf("map checked\n");
	return(0);
}