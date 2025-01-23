/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:14:24 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/17 23:14:39 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	the_exit(t_data *data)
{
	data->move++;
	data->str = ft_itoa(data->move);
	mlx_string_put(data->mlx, data->win, 200, 200, 0xFF0000, data->str);
	ft_putnbr(data->move);
	write(1, "\n", 1);
	perror("level complet !");
	clean_exit(data);
	exit(0);
}
