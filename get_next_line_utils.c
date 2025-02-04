/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:53:58 by anbaya            #+#    #+#             */
/*   Updated: 2025/01/17 22:56:45 by anbaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		j;
	char	*sub;

	i = (int)start;
	if (!s)
		return (NULL);
	if (len < 3)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	j = 0;
	sub = (char *)malloc((sizeof(char) * len) + 1);
	if (!sub)
		return (0);
	while (s[j] && j < len)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*r;

	r = (char *)s;
	j = ft_strlen(s);
	i = 0;
	while (i < j)
	{
		if (r[i] == c)
			return (r + i);
		i++;
	}
	return (0);
}

int	ft_strlcpy(char *dest, const char *src, int size)
{
	int	i;
	int	src_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

int	ft_strlcat(char *dest, const char *src, int size)
{
	int	i;
	int	j;
	int	src_len;
	int	dest_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	j = dest_len;
	while (src[i] && i < size - dest_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}
