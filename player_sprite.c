#include "so_long.h"
void ft_sleep(void)
{
    int i= 0;

    while(i<=INT_MAX/20)
        i++;
}
int player_sprite(t_data *data)
{
    int i;

    i = 0;
    while (i <= PLAYER_FRAME)
    {
        mlx_put_image_to_window (data->mlx, data->win, data->player[i], data->x, data->y);
        i++;
    }
    return (0);
}