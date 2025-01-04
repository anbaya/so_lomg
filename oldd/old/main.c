#include "mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"



int game_loop(t_game *game)
{
    int  (x), (y);

    (x = 200), (y = 200);
    if (game->key == 119 && game->player_y > 0) // 'W' key
        game->player_y -= 1;
    if (game->key == 97 && game->player_x > 0)  // 'A' key
        game->player_x -= 1;
    if (game->key == 115 && game->player_y < WINDOW_Y - game->player_sizey + 10)  // 'S' key
        game->player_y += 1;
    if (game->key == 100 && game->player_x < WINDOW_X - game->player_sizex +10)  // 'D' key
        game->player_x += 1;
    
    mlx_put_image_to_window (game->mlx, game->win, game->mp, 0, 0);
    mlx_put_image_to_window (game->mlx, game->win, game->player, game->player_x, game->player_y);
    return (0);
}

int Key_Press(int key_code, t_game *game)
{
    if (key_code == 65307)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit (0);
    }
    mlx_clear_window(game->mlx, game->win);
    game->key = key_code;
    return (0);
}
int key_release(int key_code, t_game *game)
{
    (void)key_code;
    game->key = 0;
    return (0);
}

int main()
{
    t_game *game;
    int (xmp), (ymp);

    (xmp = 400), (ymp = 400);
    game = malloc(sizeof(t_game));
    if (!game)
        return (0);
    game->map = map_reader("map.ber");
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WINDOW_X, WINDOW_Y, "Continuous Movement");
    game->mp = mlx_xpm_file_to_image(game->mlx, "map.xpm", &xmp, &ymp);
    game->player = mlx_xpm_file_to_image (game->mlx, "soldier.xpm", &game->player_sizex, &game->player_sizey);
    (game->player_x = 200), (game->player_y = 220), (game->player_sizex = 50), (game->player_sizey = 50);
    mlx_hook (game->win, 2, (1L<<0), Key_Press, game);
    mlx_hook (game->win, 3, (1L<<1), key_release, game);
    mlx_loop_hook (game->mlx, game_loop, game);
    mlx_loop(game->mlx);
    return (0);
}
