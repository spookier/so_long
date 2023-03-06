#include "../incs/so_long.h"


int spawn_player(t_all *all)
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
            if (map[two][one] == 2)
            {
                mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[1].texture_addr, j, i);
                all->player_pos.y = i;
                all->player_pos.x = j;
            }
            j += 32;
            one++;
        }
        i += 32;
        two++;
    }

    //PRINT MAP
	all->exit_flag = 0;
    all->move_counter = 0;
    printf("moves: %d\n", all->move_counter);
    printf("total collectibles: %d\n", all->collectible_counter);


    return(0);
}


int update_player(t_all *all)
{
   
    mlx_clear_window(all->engine.mlx, all->engine.mlx_win);

    check_collectible(all);

    redraw(all);
    mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[1].texture_addr, all->player_pos.x, all->player_pos.y);
    all->move_counter++;
    printf("moves: %d\n", all->move_counter);

}


int move_player_up(t_all *all)
{
    if (map[(all->player_pos.y - 32)/32][(all->player_pos.x)/32] != 1)
    {
        all->player_pos.y -= 32;
    
        update_player(all);
    }
}


int move_player_down(t_all *all)
{
    if (map[(all->player_pos.y + 32)/32][(all->player_pos.x)/32] != 1)
    {
        all->player_pos.y += 32;
    
        update_player(all);
    }

}

int move_player_left(t_all *all)
{
    if (map[(all->player_pos.y)/32][(all->player_pos.x - 32)/32] != 1)
    {
        all->player_pos.x -= 32;
    
        update_player(all);
    }
}

int move_player_right(t_all *all)
{
     if (map[(all->player_pos.y)/32][(all->player_pos.x + 32)/32] != 1)
    {
        all->player_pos.x += 32;
    
        update_player(all);
    }
}



int key_hook(int keycode, t_all *all)
{
    if(keycode == KEY_W)
        move_player_up(all);
    if(keycode == KEY_S)
        move_player_down(all);
    if(keycode == KEY_A)
        move_player_left(all);
    if(keycode == KEY_D)
        move_player_right(all);
    if (keycode == ESC)
    {
        mlx_clear_window(all->engine.mlx, all->engine.mlx_win);
        mlx_destroy_window(all->engine.mlx, all->engine.mlx_win);

        /* don't  forget to free everything */
        exit (1);
    }
    return (0);
}
