/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:04:28 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/17 23:04:33 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
}

void	draw_enemy(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->enemy, x, y);
}

void	draw_coin(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->coin, x, y);
}
