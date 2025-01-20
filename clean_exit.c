/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:23:41 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/18 17:23:48 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(int lines, char **map)
{
	int	i;

	i = -1;
	while (++i < lines)
		if (map[i])
			free(map[i]);
	free(map);
}

void	player_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->player[i])
			mlx_destroy_image(data->mlx, data->player[i]);
		i++;
	}
}

void	free_images(t_data *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->enemy)
		mlx_destroy_image(data->mlx, data->enemy);
	if (data->coin)
		mlx_destroy_image(data->mlx, data->coin);
}

int	clean_exit(t_data *data)
{
	free_images(data);
	player_free(data);
	if (data->map)
		ft_free_map(data->map_lines, data->map);
	if (data->map2)
		ft_free_map(data->map_lines, data->map2);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->map_len)
	{
		free(data->map_len);
	}
	free(data->mlx);
	if (data->str)
		free(data->str);
	free(data);
	exit(0);
}
