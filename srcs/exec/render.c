#include "../../incs/so_long.h"



// int render (t_all *data)
// {
//     //usleep(1000000);
//     return (0);
// }



static int *sprite_loader(t_all *all, char *texture_path)
{
    int *texture;
    int zero;

    zero = 0;
    texture = NULL;

    texture = mlx_xpm_file_to_image(all->engine.mlx, texture_path, &zero, &zero);
    if(!texture)
        return (NULL);
    return (texture);
}



static int load_sprites(t_all *all)
{
    all->sprites[0].texture_addr = sprite_loader(all, "sprites/block_.xpm");
    all->sprites[1].texture_addr = sprite_loader(all, "sprites/player_.xpm");
    all->sprites[2].texture_addr = sprite_loader(all, "sprites/sand_.xpm");
    all->sprites[3].texture_addr = sprite_loader(all, "sprites/exit_.xpm");
    all->sprites[4].texture_addr = sprite_loader(all, "sprites/collectible_.xpm");
    return(0);
}



int show_sprites(t_all *data)
{
    load_sprites(data);

    data->exit_flag = 0;
    data->move_counter = 0;
    fill_background(data);
    fill_wall(data);
    fill_collectible(data);
    spawn_player(data);


    printf("[OK]SPRITES INITIALIZED!\n");
    return(0);
}



int redraw(t_all *data)
{
    fill_background(data);
    fill_wall(data);
    fill_collectible(data);
    
    return(0);
}
