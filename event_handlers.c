#include "so_long.h"

int key_press(int key_code, t_data *data)
{
    if (key_code == 65307)
        clean_exit(&data);
    data->key = key_code;
    return (0);
}
int key_release(int key_code, t_data *data)
{
    (void)key_code;
    data->key = 0;
    return (0);
}