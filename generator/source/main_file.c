/*
** EPITECH PROJECT, 2022
** Dante Star
** File description:
** generator
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    map_t **map;

    if (ac != 3)
        return 84;
    if (integer_check(av[1], av[2]))
        return 84;
    map = generation(av[1], av[2]);
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j].c != '\0'; j++)
            printf("%c", map[i][j].c);
        printf("\n");
    }
    free_map(map);
    return 0;
}

map_t **generation(char *width, char *height)
{
    int x = atoi(width);
    int y = atoi(height);
    map_t **map = malloc(sizeof (map_t) * (x * y));

    map = write_grid(map, x, y);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            map[i][j].visited = 0;
    }
    map = generate(map, x, y);
    return map;
}

map_t **write_grid(map_t **map, int x, int y)
{
    int i = 0;

    for (i = 0; i < y; i++) {
        map[i] = malloc(sizeof (map_t) * (x + 1));
        if (i % 2 == 0)
            map[i] = write_cell_line(map[i], x);
        else
            map[i] = write_wall_line(map[i], x);
    }
    map[i] = NULL;
    return map;
}

map_t *write_cell_line(map_t *str, int x)
{
    int j = 1;

    str[0].c = '*';
    for (j = 1; j < x; j++) {
        if (str[j - 1].c == '*')
            str[j].c = 'X';
        else
            str[j].c = '*';
        str[j].visited = 0;
    }
    str[j].c = '\0';
    return str;
}

map_t *write_wall_line(map_t *str, int x)
{
    int j = 0;

    for (j = 0; j < x; j++) {
        str[j].c = 'X';
        str[j].visited = 0;
    }
    str[j].c = '\0';
    return str;
}
