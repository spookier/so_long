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
    return(0);
}


int	key_hook(t_all *data, int keycode)
{
	printf("Hello from key_hook!\n");
	return (0);
}


int move_player(t_all *all, int keycode)
{
    if (keycode == 13) // 13 is the keycode for the W key
	{
		printf("W key pressed!\n");
	}
	return (0);
}