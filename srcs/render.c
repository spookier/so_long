#include "../incs/so_long.h"


int render (t_all *data)
{
    fill_wall(data);
    fill_player(data);
    //usleep(1000000);
    return (0);
}
