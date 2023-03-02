#include "../incs/so_long.h"

int main(void)
{
    t_all data;

    
    //init_map(&data);

    mlx_start(&data);
    

	mlx_loop_hook(data.engine.mlx, &render, &data);

    
    mlx_loop(data.engine.mlx);
}
