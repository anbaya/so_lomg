#include "so_long.h"

void clean_exit(t_data *data)
{
    if (data->player) mlx_destroy_image(data->mlx, data->player);
    if (data->enemy) mlx_destroy_image(data->mlx, data->enemy);
    if (data->wall) mlx_destroy_image(data->mlx, data->wall);
    if (data->coin) mlx_destroy_image(data->mlx, data->coin);
    if (data->floor) mlx_destroy_image(data->mlx, data->floor);
    if (data->exit) mlx_destroy_image(data->mlx, data->exit);

    if (data->mlx && data->win) {
        mlx_clear_window(data->mlx, data->win);
        mlx_destroy_window(data->mlx, data->win);
    }
    
    if (data->mlx) mlx_destroy_display(data->mlx);
    if (data->map) free(data->map);
    if (data->map2) free(data->map2);
    if (data->map_len) free(data->map_len);
    
    free(data);
    exit(0);
}
// void	ft_free_map(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->map[i])
// 	{
// 		free(data->map[i]);
// 		i++;
// 	}
// 	free(data->map);
// }
// void	ft_free_map2(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data->map2[i])
// 	{
// 		free(data->map2[i]);
// 		i++;
// 	}
// 	free(data->map2);
// }
// void	ft_free_player(t_data *data)
// {
// 	if (data->player)
// 		mlx_destroy_image(data->mlx, data->player);

// }
