#include "so_long.h"

void the_exit(t_data *data)
{
    perror ("level complet !");
    clean_exit(data);
}