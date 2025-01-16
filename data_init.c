#include "so_long.h"

int data_init(t_data *data, char *map)
{
    if (!ft_strnstr(map, ".ber", ft_strlen(map)))
    {
        free (data);
        perror ("invalid map!!");
        exit (0);
    }
    data->map = map_reader(map , data);
    if (!is_it_map(data->map))
    {
        free (data);
        perror ("invalid map!!");
        exit (0);
    } 
    data->map2 = NULL;
    data->len = ft_strlen(data->map[0]);
    data->win_len = (data->len * SIZE) - SIZE;
    data->mlx = mlx_init ();
    data->win = mlx_new_window (data->mlx,SIZE * ft_strlen(data->map_len) , data->map_lines * SIZE, "so_long");
    data->move = 0;
    data->str = ft_itoa(data->move);
    data->frame = 0;
    data->x = 0;
    data->y = 0;
    return (0);
}