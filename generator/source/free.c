/*
** EPITECH PROJECT, 2023
** freeee
** File description:
** freee
*/

#include "my.h"

void randomize(map_t **map, int width, int height)
{
    for (int i = 0; i < height * width / 10; i ++) {
        int x = rand() % (width / 2) + 1;
        int y = rand() % (height / 2) + 1;
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
