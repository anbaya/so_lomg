/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imges.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:59:39 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/17 23:00:00 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imges(t_data *data)
{
	int	i;

	i = 0;
	data->floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &i, &i);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &i, &i);
	data->player[0] = mlx_xpm_file_to_image(data->mlx, PLAYER0, &i, &i);
	data->player[1] = mlx_xpm_file_to_image(data->mlx, PLAYER1, &i, &i);
	data->player[2] = mlx_xpm_file_to_image(data->mlx, PLAYER2, &i, &i);
	data->player[3] = mlx_xpm_file_to_image(data->mlx, PLAYER3, &i, &i);
	data->player[4] = mlx_xpm_file_to_image(data->mlx, PLAYER4, &i, &i);
	data->player[5] = mlx_xpm_file_to_image(data->mlx, PLAYER5, &i, &i);
	data->enemy = mlx_xpm_file_to_image(data->mlx, ENEMY, &i, &i);
	data->coin = mlx_xpm_file_to_image(data->mlx, COIN, &i, &i);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &i, &i);
}
