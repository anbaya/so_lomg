#include "so_long.h"

int clear_win(t_data *data)
{
    if (data->frame == 500)
    {
        mlx_clear_window(data->mlx, data->win);
        data->frame = 0;
    }
    return (0);
}