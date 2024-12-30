#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
    void *mlx;
    void *win;
    int player_x;
    int player_y;
    char *map_line_to_cmp;
    char **map;
    void *floor;
    void *wall;
    void *player;
    void *enemy;
    void *coin;
    void *exit;
    int key;
}t_data;

int key_press(int key_code, t_data *data);
int key_release(int key_code, t_data *data);

#endif