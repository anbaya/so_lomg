/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:20:23 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/17 23:22:22 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	data_init(t_data *data, char *map)
{
	*data = (t_data){0};
	if (!map_name(map))
	{
		free(data);
		perror("Error :\ninvalid map name!!");
		exit(1);
	}
	data->map = map_reader(map, data);
	if (!is_it_map(data->map))
	{
		perror("Error :\ninvalid map!!");
		clean_exit (data);
		exit(1);
	}
	data->map2 = NULL;
	data->len = ft_strlen(data->map[0]);
	data->win_len = (data->len * SIZE) - SIZE;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SIZE * ft_strlen(data->map_len),
			data->map_lines * SIZE, "so_long");
	data->str = ft_itoa(data->move);
	return (data->act = 0, 0);
}
