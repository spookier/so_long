#include <mlx.h>
#include "so_long.h"

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 600



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



int init_sprites(t_all *all, int a, int b)
{

    mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites_wall.texture_addr, a, b);
    
    return (1);
}




int fill_wall(t_all *all)
{
    int x = 0;
    int y = 0;
    
    all->sprites_wall.texture_addr = mlx_xpm_file_to_image(all->engine.mlx, "sprites/block.xpm", &x, &y);
    if (!all->sprites_wall.texture_addr)
    {
        printf("error init sprite \n");
        return (0);
    }
    int i = 0;
    int j = 0;
    while(i <= SCREEN_HEIGHT)
    {
        j = 0;
        while(j < SCREEN_WIDTH)
        {
            init_sprites(all, i, j);
            j += 32;
        }
        i += 32;
    }
}


int check_map(t_all *all)
{
    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;
    while (i <= SCREEN_HEIGHT)
    {
        j = 0;
        x = 0;
        while (j <= SCREEN_WIDTH)
        {
            if (y <= 25 && x <= 18 && all->map[y][x] == 0)
            {
                //printf("j = %d | i = %d | map[%d][%d] = %d\n", j, i, y, x, all->map[y][x]);
                mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->engine.img_addr, j, i);
            }
            x++;
            j += 32;
        }
        y++;
        i += 32;
    }
    return (0);
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


void  init_map(t_all *data)
{
    int rows = 25; 
    int cols = 18;
    

    data->map = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        data->map[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // initialize all elements to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           data->map[i][j] = 0;
        }
    }
    
    // print the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", data->map[i][j]);
        }
        printf("\n");
    }
    printf("MAP INITIALIZED!\n\n\n");
}


int render (t_all *data)
{
	printf("working!!\n");
    
    check_map(data);
    usleep(1000000);
    return (0);
}



int main(void)
{
    t_all data;

    //data.sprites_wall = (t_sprite *)malloc(sizeof(t_sprite));

    t_engine mlx;
    data.sprites_wall.texture_path = "sprites/block.xpm"; 
    data.sprites_wall.texture_addr = load_texture(&data, &mlx);
    
    init_map(&data);

    mlx_start(&data);


	mlx_loop_hook(data.engine.mlx, &render, &data);
    mlx_loop(data.engine.mlx);
}
