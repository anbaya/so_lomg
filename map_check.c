#include "so_long.h"

int coin_counter(t_data *data,char **map)
{
    int i;
    int j;
    int coins;

    i = 0;
    coins = 0;
    while (i <= data->map_lines)
    {
        j = 0;
        while (j <= ft_strlen(data->map_len))
        {
            if (map[i][j] == 'C')
                coins++;
        }
        
    }
    return (coins);
}

int exit_finder(t_data *data, char **map, int x, int y)
{
    static int c;
    static int e;

    if (x < 0 || x > ft_strlen(data->map_len) || y < 0 
    || y > data-> map_lines || map[x][y] == 'X' 
    || map[x][y] == '1' || map[x][y] == 'M')
        return (0);
    if (map[x][y] == 'C')
    {
        c++;
        map[x][y] = 'X';
    }
    if (map[x][y] == 'E')
    {
        e++;
        map[x][y] = 'X';
    }
    exit_finder (data, map, x + 1, y);
    exit_finder (data, map, x - 1, y);
    exit_finder (data, map, x, y + 1);
    exit_finder (data, map, x, y - 1);
    if (e == 1 && c == data->coins)
        return (1);
    return (0);
}
int map_checker(t_data *data)
{
    int i;
    
    data->map2 = map_dup(data);
    if (!data->map2)
        return (0);
    i = 0;
    if (!find_player_position(data))
    return (0);
    while (i < data->map_lines)
    {
        if (ft_strlen(data->map2[i]) != ft_strlen(data->map2[i + 1]))
            return (0);
    }
    data->coins = coin_counter(data, data->map2);
    if (data->coins == 0)
        return (0);
    if(!exit_finder(data, data->map2, data->player_x, data->player_y))
        return (0);
    return (1);
}