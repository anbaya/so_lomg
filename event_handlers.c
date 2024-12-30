#include "so_long.h"

int Key_press(int key_code, t_data *data)
{
    if (key_code == 65307)
    {
        mlx_destroy_window(data->mlx, data->win);
        exit (0);
    }
    mlx_clear_window(data->mlx, data->win);
    data->key = key_code;
    return (0);
}
int key_release(int key_code, t_data *data)
{
    (void)key_code;
    data->key = 0;
    return (0);
}