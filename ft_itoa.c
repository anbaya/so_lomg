/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:06:58 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/17 23:37:20 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static long int	count_len(long int nb)
{
	long int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static char	*itoing(char *r, long int nb, long int len)
{
	r[len] = '\0';
	if (nb < 0)
	{
		r[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		r[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	int		nb;
	int		len;
	char	*r;

	if (n == 0)
	{
		r = malloc(2);
		r[0] = '0';
		r[1] = '\0';
		return (r);
	}
	nb = n;
	len = count_len(n);
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (0);
	return (itoing(r, nb, len));
}
