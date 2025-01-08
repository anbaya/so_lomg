#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
#include <limits.h>

typedef struct s_data
{
    int move;
    void *mlx;
    void *win;
    int player_x;
    int player_y;
    char *map_len;
    char **map;
    char **map2;
    void *floor;
    void *wall;
    void *player[6];
    void *enemy;
    void *coin;
    int points;
    void *exit;
    int key;
    int map_lines;
    int coins;
    int len;
    int win_len;
    char *str;
    int frame;
    int x;
    int y;
}t_data;

# define SIZE 40
# define PLAYER_FRAME 5
# define WALL "textures/wall.xpm"
# define FLOOR "textures/floor.xpm"
# define PLAYER "textures/player.xpm"
# define EXIT "textures/exit.xpm"
# define ENEMY "textures/enemy.xpm"
# define COIN "textures/coin.xpm"
# define PLAYER0 "textures/player/player0.xpm"
# define PLAYER1 "textures/player/player1.xpm"
# define PLAYER2 "textures/player/player2.xpm"
# define PLAYER3 "textures/player/player3.xpm"
# define PLAYER4 "textures/player/player4.xpm"
# define PLAYER5 "textures/player/player5.xpm"

int key_press(int key_code, t_data *data);
int key_release(int key_code, t_data *data);
size_t	ft_strlen(const char *s);
void enemy(t_data *data);
int find_player_position(t_data *data);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	ft_putnbr(int n);
void ft_putchar(char c);
int	ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);
int count_lines(char *map, t_data *data);
char **map_reader(char *map, t_data *data);
int game_resolution (t_data *data);
int game_controlls(t_data *data);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char **map_dup(t_data *data);
void imges(t_data *data);
int key_w(t_data *data);
int key_s(t_data *data);
int key_a(t_data *data);
int key_d(t_data *data);
int map_checker(t_data *data);
int coin_counter(t_data *data);
void draw_player(t_data *data, int x, int y);
void draw_enemy(t_data *data, int x, int y);
void draw_coin(t_data *data, int x, int y);
int exit_finder(t_data *data, int x, int y);
void the_exit(t_data *data);
int clear_win(t_data *data);
void free_images(t_data *data);
void player_free(t_data *data);
int player_sprite(t_data *data);
void	ft_free_map(int lines, char **map);
void clean_exit(t_data **data);

#endif