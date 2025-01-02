#include "so_long.h"

int count_lines(char *map, t_data *data)
{
    int fd;
    int i;
    char *len_to_cmp;

    i = 0;
    fd = open (map, O_RDONLY, 0777);
    if (data->map_line_to_cmp = get_next_line(fd))
        i++;
    len_to_cmp = get_next_line(fd);
    while (len_to_cmp)
    {
        // if (ft_strlen(len_to_cmp) != ft_strlen(data->map_line_to_cmp));
        //     return 0;
        len_to_cmp = get_next_line(fd);
        if (len_to_cmp)
            free (len_to_cmp);
        i++;
    }
    close (fd);
    free (data->map_line_to_cmp);
    return (i);
}
 
char **map_reader(char *map, t_data *data)
{
    char **str_map;
    int lines;
    int i;
    int fd;

    lines = count_lines (map, data);
    if (!lines)
        return (0);
    str_map = malloc(sizeof (char *) * lines);
    if (!str_map)
        return (0);
    i = 0;
    fd = open(map, O_RDONLY, 0777);
    while (i < lines)
    {
        str_map[i] = get_next_line(fd);
        i++;
    }
    str_map[i] = NULL;
    close (fd);
    return (str_map);
}
int game_resolution (t_data *data)
{
    int (i), (j), (x), (y);

    (i = 0), (j = 0), (x = 0), (y = 0);
    mlx_clear_window(data->mlx, data->win);
    while(data->map[i])
    {
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
            if (data->map[i][j] == 'P')
                (mlx_put_image_to_window(data->mlx, data->win, data->player, x, y)), (data->player_x = i), (data->player_y = j);
            if (data->map[i][j] == 'M')
                mlx_put_image_to_window(data->mlx, data->win, data->enemy, x, y);
            if (data->map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->coin, x, y);
            if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
            (j++), (x += SIZE);
        }
        (i++), (y += SIZE), (j = 0), (x = 0);
    }
    return (0);
}

int game_controlls(t_data *data)
{
    if (data->key == 119 && (data->map[data->player_x][data->player_y - 1] != '1')) // 'W' key and its not wall
        key_w(data);
    if (data->key == 115 && (data->map[data->player_x][data->player_y + 1] != '1')) // 'S' key and its not wall
        key_s(data);
    if (data->key == 97 && (data->map[data->player_x - 1][data->player_y] != '1')) // 'A' key and its not wall
        key_a(data);
    if (data->key == 100 && (data->map[data->player_x + 1][data->player_y] != '1')) // 'D' key and its not wall
        key_d(data);
    return (game_resolution(data));
}

int main (int ac, char **av)
{
    int win_len;
    int fd_map;
    t_data *data;

    data = malloc(sizeof(t_data));
    if (!data)
        return (0);
    data->map = map_reader("map.ber" , data);
    win_len = (ft_strlen(data->map[0]) * SIZE) - SIZE;
    data->mlx = mlx_init ();
    data->win = mlx_new_window (data->mlx, win_len, win_len / 2, "so_long");
    imges (data);
    game_resolution (data);
    mlx_hook(data->win, 2, (1L<<0), key_press, data);
    mlx_hook(data->win, 3, (1L<<1), key_release, data);
    mlx_loop_hook(data->mlx, game_controlls, data);
    mlx_loop(data->mlx);
}