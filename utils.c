#include "so_long.h"

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
    
    map = malloc(sizeof(char *) * data->map_lines);
    i = 0;
    while (i++ <= data->map_lines)
        map[i] = ft_strdup(data->map[i]);
    return (map);
}