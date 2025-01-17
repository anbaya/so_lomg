#include "so_long.h"

int map_name(char *name)
{
    char *ber;
    int len;
    int i;
    int j;

    ber = ".ber";
    len = ft_strlen(name);
    i = len - 4;
    j = 0;
    if (len < 5)
        return (0);
    while (ber[j])
    {
        if (name[i] != ber[j])
            return (0);
        i++;
        j++;
    }
    return (1);
}