#include "../../incs/so_long.h"


static void    mlx_start(t_all *data)
{
    printf("MLX START!\n");

    data->engine.mlx = mlx_init();
    data->engine.mlx_win = mlx_new_window(data->engine.mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "so long!");
    data->engine.img = mlx_new_image(data->engine.mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
    data->engine.addr = mlx_get_data_addr(data->engine.img, &data->engine.bits_per_pixel, &data->engine.line_length,
                                         &data->engine.endian);

}


int	ft_exit(t_all *all)
{
    mlx_clear_window(all->engine.mlx, all->engine.mlx_win);
    mlx_destroy_window(all->engine.mlx, all->engine.mlx_win);

     /* don't  forget to free everything */
	//free(all->map);
	return (0);
}


int exec_main(t_pall *p)
{
    t_all data;

	data.map = p->vars.map;


    mlx_start(&data);

	//start initializing sprites
    show_sprites(&data);
    
	//free_map();

	//mlx_loop_hook(data.engine.mlx, &render, &data);
	mlx_key_hook(data.engine.mlx_win, key_hook, &data.engine);

	mlx_hook(data.engine.mlx_win, 17, 2, ft_exit, &data.engine); 

    mlx_loop(data.engine.mlx);

	
	return(0);
}
