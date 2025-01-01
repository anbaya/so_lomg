#include "so_long.h"

void imges(t_data *data)
{
    data->floor = mlx_xpm_file_to_image (data->mlx, FLOOR, SIZE, SIZE);
    data->wall = mlx_xpm_file_to_image (data->mlx, WALL, SIZE, SIZE);
    data->player = mlx_xpm_file_to_image (data->mlx, PLAYER, SIZE, SIZE);
    data->enemy = mlx_xpm_file_to_image (data->mlx, ENEMY, SIZE, SIZE);
    data->coin = mlx_xpm_file_to_image (data->mlx, COIN, SIZE, SIZE);
    data->exit = mlx_xpm_file_to_image (data->mlx, EXIT, SIZE, SIZE);
}