#include "so_long.h"

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char **map_dup(t_data *data)
{
    char **map;
    int i;
    
    if (!data->map)
		return (0);
	map = malloc(sizeof(char *) * data->map_lines + 1);
    i = 0;
    while (i < data->map_lines)
    {
        map[i] = ft_strdup(data->map[i]);
        i++;
    }
    map[i] = NULL;
    return (map);
}
int find_player_position(t_data *data)
{
    int i = 0;
    int j;

    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->player_x = i;
                data->player_y = j;
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}