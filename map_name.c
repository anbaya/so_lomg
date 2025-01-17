#include "so_long.h"

int map_walls(t_data *data, char **map)
{
    int i;
    int j;

    if (!is_one(map[0]))
        return (0);
    i = (data->map_lines - 1);
    if (!is_one(map[i]))
        return (0);
    i = 0;
    while (i < (data->map_lines - 1))
    {
        if (map[i][0] != '1')
            return (0);
        i++;
    }
    j = ft_strlen(data->map_len);
    i = 0;
    while (i < (data->map_lines - 1))
    {
        if (map[i][j - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int map_name(char *name)
{
    char *ber;
    int len;
    int i;
    int j;

    ber = ".ber";
    len = ft_strlen(name);
    i = len - 4;
    j = 0;
    if (len < 5)
        return (0);
    while (ber[j])
    {
        if (name[i] != ber[j])
            return (0);
        i++;
        j++;
    }
    return (1);
}