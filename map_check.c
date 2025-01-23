/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:01:51 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/17 23:02:49 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coin_counter(t_data *data, char c)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (i < data->map_lines)
	{
		j = 0;
		while (j <= data->len)
		{
			if (data->map2[i][j] == c)
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

int	exit_finder(t_data *data, int x, int y)
{
	static int	c;
	static int	e;

	if (x < 0 || y < 0 || x > data->len || y >= (data->map_lines)
		|| data->map2[y][x] == '1' || data->map2[y][x] == 'X')
		return (0);
	if (data->map2[y][x] == 'C')
		c++;
	else if (data->map2[y][x] == 'E')
	{
		e++;
		data->map2[y][x] = 'X';
	}
	else if (data->map2[y][x] == 'M')
		return (0);
	data->map2[y][x] = 'X';
	exit_finder(data, x + 1, y);
	exit_finder(data, x - 1, y);
	exit_finder(data, x, y + 1);
	exit_finder(data, x, y - 1);
	if (e == 1 && c == data->coins)
		return (1);
	else
		return (0);
}

void	ft_lines_and_map_len(t_data *data)
{
	int	i;

	i = ft_strlen(data->map_len);
	if (data->map_lines < 3 || data->map_lines * SIZE > 1080)
	{
		perror("invalid map size");
		clean_exit(data);
	}
	if (i < 3 || i * SIZE > 1920)
	{
		perror("invalid map size");
		clean_exit(data);
	}
}

int	is_it_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'M' && map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_data *data)
{
	int	i;

	ft_lines_and_map_len(data);
	data->map2 = map_dup(data);
	if (!data->map2)
		return (0);
	i = 0;
	if (!find_player_position(data))
		return (0);
	while (i < data->map_lines)
	{
		if (ft_strlen(data->map[i]) != data->len)
			return (0);
		i++;
	}
	if (coin_counter(data, 'P') != 1)
		return (0);
	data->coins = coin_counter(data, 'C');
	if (data->coins == 0 || (!map_walls(data, data->map)))
		return (0);
	if (!exit_finder(data, data->player_y, data->player_x))
		return (0);
	return (1);
}
