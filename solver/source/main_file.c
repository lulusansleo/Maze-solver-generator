/*
** EPITECH PROJECT, 2023
** dantes star
** File description:
** solver main
*/

#include "my.h"

static int error_handling(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    if (ac != 2)
        return -1;
    if (fd == -1)
        return -1;
    return 0;
}

int main(int ac, char **av)
{
    char **map = NULL;
    if (error_handling(ac, av) < 0)
        return 84;
    return 0;
}
