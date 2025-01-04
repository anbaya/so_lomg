#include "so_long.h"

void enemy(t_data *data)
{
    perror("you dead !");
    clean_exit(data);
}