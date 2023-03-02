#include "../mlx_linux/mlx.h"
#include "../incs/so_long.h"


#define MAP_HEIGHT 10
#define MAP_WIDTH 10



    int map[MAP_HEIGHT][MAP_WIDTH] = 
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };



static int fill_wall(t_all *all)
{
    int zero;
    int one;
    int two;
    int i;
    int j;

    one = 0;
    two = 0;
    zero = 0;
    
    
    all->sprites->texture_addr = mlx_xpm_file_to_image(all->engine.mlx, "sprites/block.xpm", &zero, &zero);

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





void    mlx_start(t_all *data)
{
    printf("LOOP START!\n");

    data->engine.mlx = mlx_init();
    data->engine.mlx_win = mlx_new_window(data->engine.mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "so long!");
    data->engine.img = mlx_new_image(data->engine.mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
    data->engine.addr = mlx_get_data_addr(data->engine.img, &data->engine.bits_per_pixel, &data->engine.line_length,
                                         &data->engine.endian);
    mlx_put_image_to_window(data->engine.mlx, data->engine.mlx_win, data->engine.img, 0, 0);
    
}



int render (t_all *data)
{
    
    fill_wall(data);
    //usleep(1000000);
    return (0);
}

