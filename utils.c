#include "so_long.h"

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
	size_t	size;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (!dest)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}

char **map_dup(t_data *data)
{
    char **map;
    int i;
    
    if (!data->map)
		return (0);
	map = malloc(sizeof(char *) * data->map_lines);
    i = 0;
    while (i++ <= data->map_lines)
        map[i] = ft_strdup(data->map[i]);
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
                data->player_x = j;
                data->player_y = i;
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}