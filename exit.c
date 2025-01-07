#include "so_long.h"

void the_exit(t_data *data)
{
    data->move++;
    data->str = ft_itoa(data->move);
    mlx_string_put(data->mlx, data->win, 200, 200, 0xFF0000, data->str);
    ft_putnbr(data->move);
    write (1, "\n", 1);
    perror ("level complet !");
    clean_exit(&data);
    exit(0);
}