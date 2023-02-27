/*
** EPITECH PROJECT, 2023
** freeee
** File description:
** freee
*/

#include "my.h"

void free_map(map_t **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
