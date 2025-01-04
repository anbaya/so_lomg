#include "so_long.h"

void the_exit(t_data *data)
{
    if (data->points == data->coins)
    {
        perror ("level complet !");
        clean_exit(data);
    }
}