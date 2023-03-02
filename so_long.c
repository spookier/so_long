#include <mlx.h>
#include "so_long.h"

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600

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



void    my_mlx_pixel_put(t_all *data, t_v2i pos, int color)
{
    char    *dst;
	if(pos[0] < 0 || pos[1] < 0 || pos[0] >= SCREEN_WIDTH || pos[1] >= SCREEN_HEIGHT)
		return ;
    dst = data->engine.addr + (pos[1] * data->engine.line_length + pos[0] * (data->engine.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    draw_rect(t_all *data, t_v2i start, t_v2i dim, int color)
{
    t_v2i   pos;

    pos[1] = 0;
    while (pos[1] < dim[1])
    {
        pos[0] = 0;
        while (pos[0] < dim[0])
        {
            my_mlx_pixel_put(data, start + pos, color);
            pos[0]++;
        }
        pos[1]++;
    }
}



int fill_wall(t_all *all)
{
    int x = 0;
    int y = 0;

    int one;
    int two;

    one = 0;
    two = 0;
    
    all->sprites->texture_addr = mlx_xpm_file_to_image(all->engine.mlx, "sprites/block.xpm", &x, &y);

    int i = 0;
    int j = 0;
    
    while(two < MAP_HEIGHT)
    {
        j = 0;
        one = 0;
        while(one < MAP_WIDTH)
        {
            if (map[two][one] == 1)
            {
                mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[0].texture_addr, j, i);
            }
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
	//printf("working!!\n");
    
    //check_map(data);
    fill_wall(data);
    usleep(1000000);
    return (0);
}

int main(void)
{
    t_all data;

    
    //init_map(&data);

    mlx_start(&data);


	mlx_loop_hook(data.engine.mlx, &render, &data);

    
    mlx_loop(data.engine.mlx);
}
