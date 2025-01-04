#include "so_long.h"

int key_a(t_data *data) // move up
{
    if (data->map[data->player_x][data->player_y - 1] == 'C')
        data->points++;
    else if(data->map[data->player_x][data->player_y - 1] == 'M')
        enemy(data);
    else if(data->map[data->player_x][data->player_y - 1] == 'E')
        the_exit(data);
    data->map[data->player_x][data->player_y - 1] = 'P';
    data->map[data->player_x][data->player_y] = '0';
    data->player_y -= 1;
    return (0);
}

int key_d(t_data *data) // move down
{
    if (data->map[data->player_x][data->player_y + 1] == 'C')
        data->points++;
    else if (data->map[data->player_x][data->player_y + 1] == 'M')
        enemy(data);
    else if (data->map[data->player_x][data->player_y + 1] == 'E')
        the_exit(data);
    data->map[data->player_x][data->player_y + 1] = 'P';
    data->map[data->player_x][data->player_y] = '0';
    data->player_y += 1;
    return (0);
}

int key_w(t_data *data) // move left
{
    if (data->map[data->player_x - 1][data->player_y] == 'C')
        data->points++;
    else if (data->map[data->player_x - 1][data->player_y] == 'M')
        enemy(data);
    else if (data->map[data->player_x - 1][data->player_y] == 'E')
        the_exit(data);
    data->map[data->player_x - 1][data->player_y] = 'P';
    data->map[data->player_x][data->player_y] = '0';
    data->player_x -= 1;
    return (0);
}

int key_s(t_data *data) // move right
{
    if (data->map[data->player_x + 1][data->player_y] == 'C')
        data->points++;
    else if (data->map[data->player_x + 1][data->player_y] == 'M')
        enemy(data);
    else if (data->map[data->player_x + 1][data->player_y] == 'E')
        the_exit(data);
    data->map[data->player_x + 1][data->player_y] = 'P';
    data->map[data->player_x][data->player_y] = '0';
    data->player_x += 1;
    return (0);
}