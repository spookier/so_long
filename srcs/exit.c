#include "../incs/so_long.h"

int fill_exit(t_all *all)
{
    int zero;
    int one;
    int two;
    int i;
    int j;

    one = 0;
    two = 0;
    zero = 0;
 
    i = 0;
    while(two < MAP_HEIGHT)
    {
        j = 0;
        one = 0;
        while(one < MAP_WIDTH)
        {
            if (map[two][one] == 3)
                mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[3].texture_addr, j, i);
            j += 32;
            one++;
        }
        i += 32;
        two++;
    }
        spawn_exit(all);
    return(0);
}

int spawn_exit(t_all *all)
{
    printf("exit flag = %d\n", all->exit_flag);

    if(all->exit_flag == 1 && map[(all->player_pos.y)/32][(all->player_pos.x)/32] == 3)
    {
            exit(0);
    }
    return(0);
}


