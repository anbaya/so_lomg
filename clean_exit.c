#include "so_long.h"

void	ft_free_map(int lines, char **map)
{
	int	i;

	i = 0;

	while (i < lines)
	{
		if (map[i])
		{
			free (map[i]);
		}
		i++;
	}
	free(map);
}
void player_free(t_data *data)
{
	int i;

	i = 0;
	while (data->player[i])
	{
		if (data->player[i])
			free (data->player[i]);
		i++;
	}
}

void clean_exit(t_data **data)
{
	player_free((*data));
	if ((*data)->wall)
		mlx_destroy_image((*data)->mlx, (*data)->wall);
	if ((*data)->floor)
		mlx_destroy_image((*data)->mlx, (*data)->floor);
	if ((*data)->exit)
		mlx_destroy_image((*data)->mlx, (*data)->exit);
	if ((*data)->enemy)
		mlx_destroy_image((*data)->mlx, (*data)->enemy);
	if ((*data)->coin)
		mlx_destroy_image((*data)->mlx, (*data)->coin);
    if ((*data)->map)
		ft_free_map((*data)->map_lines, (*data)->map);
	if ((*data)->map2)
		ft_free_map((*data)->map_lines, (*data)->map2);
	if ((*data)->win)
		mlx_destroy_window((*data)->mlx, (*data)->win);
	if ((*data)->mlx)
		mlx_destroy_display((*data)->mlx);
    if ((*data)->map_len)
        free ((*data)->map_len);
	free((*data)->mlx);
    free (*data);
	exit(0);
}

