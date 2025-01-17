/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:25:24 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/17 23:25:42 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sleep(void)
{
	int	i;

	i = 0;
	while (i <= INT_MAX / 20)
		i++;
}

int	player_sprite(t_data *data)
{
	int	i;

	i = 0;
	while (i <= PLAYER_FRAME)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->player[i], data->x,
			data->y);
		i++;
	}
	return (0);
}
