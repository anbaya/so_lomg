#include "so_long.h"

int data_init(t_data *data, char *map)
{
    data->map = map_reader(map , data);
    data->map2 = NULL;
    data->len = ft_strlen(data->map[0]);
    data->win_len = (data->len * SIZE) - SIZE;
    data->mlx = mlx_init ();
    data->win = mlx_new_window (data->mlx, data->win_len + SIZE, data->win_len / 2 + (SIZE / 2), "so_long");
    data->move = 0;
    data->str = ft_itoa(data->move);
    data->frame = 0;
    data->x = 0;
    data->y = 0;
    return (0);
}