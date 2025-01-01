#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

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
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);
int count_lines(char *map, t_data *data);
int **map_reader(char *map, t_data *data);
int game_resolution (t_data *data);
int game_controlls(t_data *data);
int w(t_data *data);
int s(t_data *data);
int a(t_data *data);
int d(t_data *data);


#endif