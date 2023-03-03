#include "../incs/so_long.h"

int fill_player(t_all *all)
{
    int zero;
    int one;
    int two;
    int i;
    int j;

    one = 0;
    two = 0;
    zero = 0;
    
    
    all->sprites[1].texture_addr = mlx_xpm_file_to_image(all->engine.mlx, "sprites/player.xpm", &zero, &zero);

    i = 0;
    while(two < MAP_HEIGHT)
    {
        j = 0;
        one = 0;
        while(one < MAP_WIDTH)
        {
            if (map[two][one] == 2)
                mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[1].texture_addr, j, i);
            j += 32;
            one++;
        }
        i += 32;
        two++;
    }
}
