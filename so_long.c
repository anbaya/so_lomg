#include "so_long.h"

int game_resolution(int fd, t_data data)
{
    
}

int main(int ac, char **av)
{
    int win_len;
    int fd_map;
    t_data *data;

    fd_map = open(av[1], O_RDWR, 0777);
    win_len = get_next_line (fd_map);
    data->mlx = mlx_init ();
    data->win = mlx_new_window (data->mlx, win_len, win_len, "so_long");
    game_resolution (fd, data);
    mlx_hook(data->win, 2, (1L<<0), key_press, data);
    mlx_hook(data->win, 3, (1L<<1), key_relase, data);
    mlx_loop_hook(data->mlx, game_controlls, data);
    mlx_loop(data->mlx);
}