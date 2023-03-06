/*
** EPITECH PROJECT, 2023
** dantes star
** File description:
** generator
*/

#include "my.h"

map_t **generate(map_t **map, int x, int y)
{
    vector_t vector = gen_vector(0, 0, x, y), size = {x - 1, y - 1};
    srand(time(0));
    create_path(map, 0, 0, size);
    return map;
}

int check_adjacent(map_t **map, int x, int y, vector_t size)
{
    int a = 0;

    if (x + 2 > size.x || map[y][x + 2].visited == 1)
        a++;
    if (x - 2 < 0 || map[y][x - 2].visited == 1)
        a++;
    if (y + 2 > size.y || map[y + 2][x].visited == 1)
        a++;
    if (y - 2 < 0 || map[y - 2][x].visited == 1)
        a++;
    return a;
}

void create_path(map_t **map, int x, int y, vector_t size)
{
    vector_t vector = gen_vector(x, y, size.x, size.y);
    map[y][x].visited = 1;
    if (check_adjacent(map, x, y, size) == 4)
        return;
    while (map[y + vector.y][x + vector.x].visited == 1) {
        vector = gen_vector(x, y, size.x, size.y);
    }
    map[y + vector.y / 2][x + vector.x / 2].c = '*';
    for (int i = 0; i < 4; i++) {
        create_path(map, x + vector.x, y + vector.y, size);
    }
}

vector_t gen_vector(int x, int y, int width, int height)
{
    int a = 0;
    vector_t vector = {0, 0};

    a = rand() % 4;
    if (a == 0)
        vector.x = 2;
    if (a == 1)
        vector.x = -2;
    if (a == 2)
        vector.y = 2;
    if (a == 3)
        vector.y = -2;
    if (x + vector.x < 0 || x + vector.x > width)
        vector.x = -vector.x;
    if (y + vector.y < 0 || y + vector.y > height)
        vector.y = -vector.y;
    return vector;
}
