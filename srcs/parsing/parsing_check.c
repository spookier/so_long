#include "parsing.h"

static void check_map_validity(t_pall *all)
{
    int i;
	
	i = 0;
    while (i < all->vars.rows_map) 
	{
        int j = 0;
        while (j < all->vars.chars_map) 
		{
            if (all->vars.map[i][j] == 'E') 
				all->items.exit++;
            else if (all->vars.map[i][j] == 'C') 
               all->items.collectibles++;
            else if (all->vars.map[i][j] == 'P') 
				all->items.start++;
            j++;
        }
        i++;
    }
}


static int init_items(t_pall *all)
{
	all->items.start = 0;
	all->items.exit = 0;
	all->items.collectibles = 0;

	check_map_validity(all);
	if (all->items.start < 1 || all->items.exit < 1 || all->items.collectibles < 1) 
	{
		ft_printf("Error\nNot enough map components\n");
		return(1);
	}
	return(0);
}


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

int init_check_map(t_pall *all)
{
	if(all->vars.rows_map < 3 || all->vars.chars_map < 2)
	{
		ft_printf("Error\nInvalid map\n");
		return(1);
	}

	if(check_rectangle(&all->vars) == 1 || init_items(all) == 1)
		return(1);

	printf("map checked\n");
	return(0);
}