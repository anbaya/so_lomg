#include "so_long.h"

void find_player_position(t_data *data)
{
    int i = 0;
    int j;

    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'P')
            {
                data->player_x = j; // Column index
                data->player_y = i; // Row index
                return;
            }
            j++;
        }
        i++;
    }
}
