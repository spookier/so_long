#include "../incs/so_long.h"

int map[MAP_HEIGHT][MAP_WIDTH] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		
};



static void    mlx_start(t_all *data)
{
    printf("MLX START!\n");

    data->engine.mlx = mlx_init();
    data->engine.mlx_win = mlx_new_window(data->engine.mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "so long!");
    data->engine.img = mlx_new_image(data->engine.mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
    data->engine.addr = mlx_get_data_addr(data->engine.img, &data->engine.bits_per_pixel, &data->engine.line_length,
                                         &data->engine.endian);
    mlx_put_image_to_window(data->engine.mlx, data->engine.mlx_win, data->engine.img, 0, 0);
	//mlx_key_hook(data->engine.mlx_win, move_player, &data);

    
}



int main(void)
{
    t_all data;


    mlx_start(&data);
    show_sprites(&data);
    
	mlx_loop_hook(data.engine.mlx, &render, &data);


    
    mlx_loop(data.engine.mlx);
}