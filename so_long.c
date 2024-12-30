#include "mlx.h"
#include <fcntl.h>
#include "so_long.h"

int count_lines(char *map)
{
    int fd;
    int i;
    char *len_to_cmp;

    i = 0;
    fd = open (av[1], O_RDWR, 0777);
    if (data->map_line_to_cmp = get_next_line(fd))
        i++;
    while (len_to_cmp = get_next_line(fd))
    {
        if (ft_strlen(len_to_cmp) != ft_strlen(data->map_line_to_cmp));
            return 0;
        i++;
    }
    close (fd);
    return (i);
}
 
int **map_reader(char *map, t_data data)
{
    char **str_map;
    int lines;
    int i;
    int fd;

    lines = count_lines (map);
    if (!lines)
        return (0);
    str_map = malloc(sizeof (char *) * lines);
    if (!str_map)
        return (0);
    i = 0;
    fd = open(map, O_RDWR, 0777)
    while (i <= lines)
    {
        str_map[i] = get_next_line(fd);
        i++;
    }
    close (fd);
    return (str_map);
}
int game_resolution (char *map_path, t_data data, int win_len)
{
    int (i), (j), (x), (y);

    (i = 0), (j = 0), (x = 0), (y = 0);
    mlx_clear_window(data->mlx, data->win);
    while(data->map[i])
    {
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0')
                mlx_put_image_to_window();
            if (data->map[i][j] == '1')
                mlx_put_image_to_window();
            if (data->map[i][j] == 'P')
                mlx_put_image_to_window();
            if (data->map[i][j] == 'E')
                mlx_put_image_to_window();
            j++;
        }
        i++;
    }
}

int main (int ac, char **av)
{
    int win_len;
    int fd_map;
    t_data *data;

    fd_map = open(av[1], O_RDWR, 0777);
    win_len = ft_strlen(get_next_line (fd_map)) * 20;
    close (fd_map)
    data->mlx = mlx_init ();
    data->win = mlx_new_window (data->mlx, win_len, win_len, "so_long");
    data->map = map_reader(av[1], data);
    game_resolution (av[1], data, win_len);
    mlx_hook(data->win, 2, (1L<<0), key_press, data);
    mlx_hook(data->win, 3, (1L<<1), key_relase, data);
    mlx_loop_hook(data->mlx, game_controlls, data);
    mlx_loop(data->mlx);
}