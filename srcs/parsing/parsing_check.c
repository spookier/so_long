#include "parsing.h"

// static void check_map_validity(t_pvars *v, t_items *item)
// {
//     int i;
	
// 	i = 0;
//     while (i < v->rows_map) 
// 	{
//         int j = 0;
//         while (j < v->chars_map) 
// 		{
//             if (v->map[i][j] == 'E') 
// 				item->exit++;
//             else if (v->map[i][j] == 'C') 
//                 item->collectibles++;
//             else if (v->map[i][j] == 'P') 
// 				item->start;
//             j++;
//         }
//         i++;
//     }
// }


// static int init_items(t_pvars *v, t_items *item)
// {
// 	item->start = 0;
// 	item->exit = 0;
// 	item->collectibles = 0;
// 	check_map_validity(v, item);
// 	if(item->start > 1 || item->exit > 1 || item->collectibles < 1)
// 		return(1);
// }


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

	if(check_rectangle(&all->vars) == 1)
		return(1);
	

	printf("map checked\n");
	return(0);
}