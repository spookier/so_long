#include "../../incs/so_long.h"

int fill_collectible(t_all *all)
{
    int one;
    int two;
    int i;
    int j;

    one = 0;
    two = 0;
    all->collectible_counter = 0;
 
    i = 0;
    while(two < MAP_HEIGHT)
    {
        j = 0;
        one = 0;
        while(one < MAP_WIDTH)
        {
            if (map[two][one] == 4)
            {
                mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[4].texture_addr, j, i);
                all->collectible_counter++;
            }
            j += 32;
            one++;
        }
        i += 32;
        two++;
    }
    return(0);
}

int eat_collectible(t_all *all)
{
    map[all->player_pos.y / 32][all->player_pos.x / 32] = 0;

    if(all->collectible_counter - 1 == 0)
        all->exit_flag = 1;

    all->collectible_counter--;

    printf("collectibles remaining: %d\n", all->collectible_counter);
    return(0);
}


int check_collectible(t_all *all)
{
    if(map[all->player_pos.y / 32][all->player_pos.x / 32] == 4)
        eat_collectible(all);

    return(0);
}

