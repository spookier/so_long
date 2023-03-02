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

    mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->sprites[0].texture_addr, a, b);
    
    return (1);
}




int fill_wall(t_all *all)
{
    int x = 0;
    int y = 0;
    
    all->sprites[0].texture_addr = mlx_xpm_file_to_image(all->engine.mlx, "sprites/block.xpm", &x, &y);
    if (!all->sprites[0].texture_addr)
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

int	xpm_texture_pixel_get(t_all *data, int i, int x, int y)
{
	int	*dst;

	dst = data->sprites[i].texture_addr
		+ (x * data->sprites[i].texture_bits_per_pixel / 8)
		+ (y * data->sprites[i].texture_line_length + x);
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put_2(t_engine *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (x * mlx->bits_per_pixel / 8) + (y * mlx->line_length);
	*(unsigned int *)dst = color;
}

int check_map(t_all *all)
{
    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;
    // while (i <= SCREEN_HEIGHT)
    // {
    //     j = 0;
    //     x = 0;
    //     while (j <= SCREEN_WIDTH)
    //     {
    //         if (y <= 25 && x <= 18 && all->map[y][x] == 0)
    //         {
    //             //printf("j = %d | i = %d | map[%d][%d] = %d\n", j, i, y, x, all->map[y][x]);
    //            // mlx_put_image_to_window(all->engine.mlx, all->engine.mlx_win, all->engine.img_addr, j, i);
    //            int color = xpm_texture_pixel_get(all, 0, i, j);
    //            printf("%d\n", color);
    //            my_mlx_pixel_put_2(&all->engine, i, j, color);
    //         }
    //         x++;
    //         //j += 32;
    //         j++;
    //     }
    //     y++;
    //     //i += 32;
    //     i++;
    // }
    if (all->map[0][0] == 0)
    {
        while (i <= 32)
        {
            while (j <= 32)
            {
                int color = xpm_texture_pixel_get(all, 0, i, j);
                printf("%d\n", color);
                my_mlx_pixel_put_2(&all->engine, i, j, color);
            }
            j++;
        }
        i++;
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

void	put_obj_texture_value(t_all *data, t_engine *img, int i)
{
	data->sprites[i].texture_width = img->img_width;
	data->sprites[i].texture_height = img->img_height;
	data->sprites[i].texture_line_length = img->line_length;
	data->sprites[i].texture_bits_per_pixel = img->bits_per_pixel;
}

int	*load_texture(t_all *data, t_engine *img, int i)
{
	int	row;
	int	col;
	int	*res;

	img->img = mlx_xpm_file_to_image(data->engine.mlx,
			data->sprites[i].texture_path, &img->img_width, &img->img_height);
	if (!(img->img))
		return (NULL);
	img->img_addr = (int *)mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	if (!(img->img_addr))
		return (NULL);
	res = (int *)malloc(sizeof(int) * (img->img_width * img->img_height));
	row = -1;
	while (++row < img->img_height)
	{
		col = -1;
		while (++col < img->img_width)
			res[img->img_width * row + col]
				= img->img_addr[img->img_width * row + col];
	}
	mlx_destroy_image(data->engine.mlx, img->img);
	put_obj_texture_value(data, img, i);
	return (res);
}

int main(void)
{
    t_all data;
    
    init_map(&data);

    mlx_start(&data);

    t_engine *texture;

    data.sprites[0].texture_path = "sprites/block.xpm";
    data.sprites[0].texture_addr = load_texture(&data, &texture, 0);

	mlx_loop_hook(data.engine.mlx, &render, &data);
    mlx_loop(data.engine.mlx);
}
