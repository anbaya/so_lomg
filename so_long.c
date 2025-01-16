#include "so_long.h"

int count_lines(char *map, t_data *data)
{
    int fd;
    int i;
    char *len_to_cmp;

    i = 0;
    fd = open (map, O_RDONLY);
    data->map_len = get_next_line(fd);
    if (data->map_len)
        i++;
    len_to_cmp = get_next_line(fd);
    while (len_to_cmp)
    {
        if (len_to_cmp)
            free (len_to_cmp);
        len_to_cmp = get_next_line(fd);
        i++;
    }
    close (fd);
    data->map_lines = i;
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
    str_map = (char **)malloc(sizeof (char *) * (lines + 1));
    if (!str_map)
        return (0);
    i = 0;
    fd = open(map, O_RDONLY);
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
    while(data->map[i])
    {
        while (data->map[i][j])
        {
            if (data->map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
            if (data->map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
            if (data->map[i][j] == 'P')
                (data->x = x), (data->y = y);
            if (data->map[i][j] == 'M')
                draw_enemy(data, x, y);
            if (data->map[i][j] == 'C')
                draw_coin(data, x, y);
            if (data->map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
            (j++), (x += SIZE);
        }
        (i++), (y += SIZE), (j = 0), (x = 0);
    }
    mlx_string_put(data->mlx, data->win, 20, 20, 0xFF0000, data->str);
    free(data->str);
    return (0);
}

int game_controlls(t_data *data)
{
    if (data->key == 97 && (data->map[data->player_x][data->player_y - 1] != '1') 
    && (data->player_y - 1 >= 0)) // 'A' key and its not wall
        key_a(data);
    if (data->key == 100 && (data->map[data->player_x][data->player_y + 1] != '1') 
    && (data->player_y + 1 <= data->len)) // 'D' key and its not wall
        key_d(data);
    if (data->key == 119 && (data->map[data->player_x - 1][data->player_y] != '1') 
    && data->player_x - 1 >= 0) // 'W' key and its not wall
        key_w(data);
    if (data->key == 115 && (data->map[data->player_x + 1][data->player_y] != '1')
    && data->player_x + 1 <= data->map_lines) // 'S' key and its not wall
        key_s(data);
    clear_win(data);
    if (data->key == 97 || data->key == 100 || data->key == 119 
    || data->key == 115)
    {
        game_resolution(data);
        data->key = 0;
        data->frame++;
    }
    player_sprite(data);
    return (0);
}

int main (int ac, char **av)
{
    t_data *data;

    if (ac == 2)
    { 
        data = malloc(sizeof(t_data));
        if (!data)
        {
            perror ("memory error!!");
            return (0);
        }
        data_init(data, av[1]);
        if (!map_checker(data))
        {
            perror ("invalid map!!");
            clean_exit(data);
        }
        imges (data);
        game_resolution (data);
        mlx_hook(data->win, 2, (1L<<0), key_press, data);
        mlx_hook(data->win, 3, (1L<<1), key_release, data);
        mlx_hook(data->win, 17, 0, clean_exit, data);
        mlx_loop_hook(data->mlx, game_controlls, data);    
        mlx_loop(data->mlx);
    }
    return (perror("no input"), 0);
}