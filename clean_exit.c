#include "so_long.h"

void clean_exit(t_data *data)
{
    mlx_destroy_image (data->mlx, data->player);
    mlx_destroy_image (data->mlx, data->enemy);
    mlx_destroy_image (data->mlx, data->wall);
    mlx_destroy_image (data->mlx, data->coin);
    mlx_destroy_image (data->mlx, data->floor);
    mlx_destroy_image (data->mlx, data->exit);
    mlx_clear_window (data->mlx, data->win);
    mlx_destroy_window (data->mlx, data->win);
    mlx_destroy_display (data->mlx);
    free (data->map);
    free (data->map2);
    free (data);
}