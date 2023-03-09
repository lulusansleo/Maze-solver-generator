/*
** EPITECH PROJECT, 2023
** freeee
** File description:
** freee
*/

#include "my.h"

void randomize(map_t **map, int width, int height)
{
    int x = 0;
    int y = 0;
    srand(time(0));
    for (int i = 0; i < height * width / 10; i ++) {
        x = rand() % (width);
        y = rand() % (height);
        if (map[y][x].c == 'X')
            map[y][x].c = '*';
    }
}

void free_map(map_t **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
