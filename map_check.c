#include "so_long.h"

int coin_counter(t_data *data)
{
    int i;
    int j;
    int coins;

    i = 0;
    coins = 0;
    while (i < data->map_lines)
    {
        j = 0;
        while (j <= data->len)
        {
            if (data->map2[i][j] == 'C')
                coins++;
            j++;
        }
        i++;
    }
    return (coins);
}

int exit_finder(t_data *data, int x, int y)
{
    static int c;
    static int e;

	if (x < 0 || y < 0 || x > data->len || y > data->map_lines
		|| data->map2[y][x] == '1' || data->map2[y][x] == 'X')
		return (0);
	if (data->map2[y][x] == 'C')
		c++;
	else if (data->map2[y][x] == 'E')
	{
		e++;
		data->map2[y][x] = 'X';
		return (0);
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
        if (ft_strlen(data->map[i]) != data->len)
            return (0);
        i++;
    }
    data->coins = coin_counter(data);
    if (data->coins == 0)
        return (0);
    if(!exit_finder(data, data->player_y, data->player_x))
        return (0);
    return (1);
}