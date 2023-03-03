#include "../incs/so_long.h"

int map[MAP_HEIGHT][MAP_WIDTH] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 2, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};



int fill_wall(t_all *all)
{
    int zero;
    int one;
    int two;
    int i;
    int j;

    one = 0;
    two = 0;
    zero = 0;
    
    
    all->sprites[0].texture_addr = mlx_xpm_file_to_image(all->engine.mlx, "sprites/block.xpm", &zero, &zero);

    i = 0;
    while(two < MAP_HEIGHT)
    {
        j = 0;
        one = 0;
        while(one < MAP_WIDTH)
        {
            if (map[two][one] == 1)
                mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[0].texture_addr, j, i);
            printf("map[%d][%d]=%d\n", two, one, map[two][one]);
            j += 32;
            one++;
        }
        i += 32;
        two++;
    }
}






