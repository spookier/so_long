    #include "../../incs/so_long.h"


    static void    mlx_start(t_all *data)
    {
        printf("MLX START!\n");

        data->engine.mlx = mlx_init();
        data->engine.mlx_win = mlx_new_window(data->engine.mlx, data->SCREEN_HEIGHT, data->SCREEN_WIDTH, "so long!");
        data->engine.img = mlx_new_image(data->engine.mlx, data->SCREEN_HEIGHT, data->SCREEN_WIDTH);
        data->engine.addr = mlx_get_data_addr(data->engine.img, &data->engine.bits_per_pixel, &data->engine.line_length,
                                            &data->engine.endian); 
    }

    int	ft_exit(t_all *all)
    {

        mlx_destroy_image(all->engine.mlx, all->sprites[0].texture_addr);
        if(all->sprites[0].texture_addr)
            printf("1 HAS value\n");
        else
            printf("1 NO value\n");
        usleep(10000000);

        mlx_destroy_image(all->engine.mlx, all->sprites[1].texture_addr);
        mlx_destroy_image(all->engine.mlx, all->sprites[2].texture_addr);
        mlx_destroy_image(all->engine.mlx, all->sprites[3].texture_addr);
        mlx_destroy_image(all->engine.mlx, all->sprites[4].texture_addr);
        free(all->map);
        mlx_clear_window(all->engine.mlx, all->engine.mlx_win);
        mlx_destroy_window(all->engine.mlx, all->engine.mlx_win);

        /* don't  forget to free everything */
        return (0);
    }


    void find_map_size(t_all *data, t_pall *parsing)
    {

        data->MAP_WIDTH = parsing->vars.chars_map;
        data->MAP_HEIGHT = parsing->vars.rows_map;

        int map_width_px = parsing->vars.rows_map * TILE_SIZE;
        int map_height_px = parsing->vars.chars_map * TILE_SIZE;

        data->SCREEN_WIDTH = map_width_px;
        data->SCREEN_HEIGHT = map_height_px;
	}


    int exec_main(t_pall *p)
    {
        t_all data;
        data.check_exit_ESC = 0;

        data.map = p->vars.map;
		find_map_size(&data, p);


		mlx_start(&data);

        //start initializing sprites
        show_sprites(&data);
        
        //free_map();

        //mlx_loop_hook(data.engine.mlx, &render, &data);

        mlx_key_hook(data.engine.mlx_win, key_hook, &data.engine);



   
        //mlx_hook(data.engine.mlx_win, 17, 2, ft_exit, &data.engine); 

        mlx_loop(data.engine.mlx);

        return(0);
    }
