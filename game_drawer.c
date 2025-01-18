/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvdata->in@42.fr>                      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:22:14 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/18 17:22:18 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_drawer(t_data *data)
{
	if (data->map[data->d_i][data->d_j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor, data->d_x,
			data->d_y);
	if (data->map[data->d_i][data->d_j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, data->d_x,
			data->d_y);
	if (data->map[data->d_i][data->d_j] == 'P')
	{
		(data->x = data->d_x);
		(data->y = data->d_y);
	}
	if (data->map[data->d_i][data->d_j] == 'M')
		draw_enemy(data, data->d_x, data->d_y);
	if (data->map[data->d_i][data->d_j] == 'C')
		draw_coin(data, data->d_x, data->d_y);
	if (data->map[data->d_i][data->d_j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, data->d_x,
			data->d_y);
	return (0);
}
