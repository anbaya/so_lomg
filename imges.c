#include "so_long.h"

void imges(t_data *data)
{
    int i;

    i = i;
    data->floor = mlx_xpm_file_to_image (data->mlx, FLOOR, &i, &i);
    data->wall = mlx_xpm_file_to_image (data->mlx, WALL, &i, &i);
    data->player = mlx_xpm_file_to_image (data->mlx, PLAYER, &i, &i);
    data->enemy = mlx_xpm_file_to_image (data->mlx, ENEMY, &i, &i);
    data->coin = mlx_xpm_file_to_image (data->mlx, COIN, &i, &i);
    data->exit = mlx_xpm_file_to_image (data->mlx, EXIT, &i, &i);
}