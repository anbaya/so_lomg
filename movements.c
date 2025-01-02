#include "so_long.h"

int key_a(t_data *data) // move up
{
    data->map[data->player_x][data->player_y - 1] = 'P';
    data->map[data->player_x][data->player_y] = '0';
    data->player_y -= 1;
    return (0);
}

int key_d(t_data *data) // move down
{
    data->map[data->player_x][data->player_y + 1] = 'P';
    data->map[data->player_x][data->player_y] = '0';
    data->player_y += 1;
    return (0);
}

int key_w(t_data *data) // move left
{
    data->map[data->player_x - 1][data->player_y] = 'P';
    data->map[data->player_x][data->player_y] = '0';
    data->player_x -= 1;
    return (0);
}

int key_s(t_data *data) // move right
{
    data->map[data->player_x + 1][data->player_y] = 'P';
    data->map[data->player_x][data->player_y] = '0';
    data->player_x += 1;
    return (0);
}