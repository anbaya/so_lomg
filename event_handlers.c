/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:24:38 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/18 17:24:41 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key_code, t_data *data)
{
	if (key_code == 65307)
		clean_exit(data);
	data->key = key_code;
	return (0);
}

int	key_release(int key_code, t_data *data)
{
	(void)key_code;
	data->key = 0;
	return (0);
}
