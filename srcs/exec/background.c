#include "../../incs/so_long.h"

int fill_background(t_all *all)
{
    int one;
    int two;
    int i;
    int j;

    one = 0;
    two = 0;
 
    i = 0;
    while(two < all->MAP_HEIGHT)
    {
        j = 0;
        one = 0;
        while(one < all->MAP_WIDTH)
        {
            if (all->map[two][one] == '0' || all->map[two][one] == 'P' || (all->map[two][one] == 'E' && all->exit_flag == 0))
                mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[2].texture_addr, j, i);
            j += 32;
            one++;
        }
        i += 32;
        two++;
    }
    return(0);
}
