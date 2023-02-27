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
    for (int i = 0; i < y - 2 || i + 1 < y - 1; i += 2) {
        for (int j = 0; j < x - 2 || j + 1 < x - 1; j += 2) {
            create_path(map, j, i, size);
        }
    }
    return map;
}

int check_adjacent(map_t **map, int x, int y, vector_t size)
{
    int count = 0;
    if (y + 1 == size.y || y == size.y)
        count += 1;
    else {
        if (map[y + 2][x].visited == 1)
            count += 1;
    }
    if (y == 0 || map[y - 2][x].visited == 1)
        count += 1;
    if (x + 1 == size.x || x == size.x)
        count += 1;
    else {
        if (map[y][x + 2].visited == 1)
            count += 1;
    }
    if (x == 0 || map[y][x - 2].visited == 1)
        count += 1;
    if (count == 4)
        return 1;
    return 0;
}

void create_path(map_t **map, int x, int y, vector_t size)
{
    vector_t vector = gen_vector(x, y, size.x, size.y);
    int new_x = x + vector.x;
    int new_y = y + vector.y;
    if (new_x < 0 || new_x > size.x || new_y < 0 || new_y > size.y) {
        return;
    }
    if (map[new_y][new_x].visited == 1) {
        return;
    }
    if (check_adjacent(map, new_x, new_y, size) == 0) {
        map[y + vector.y / 2][x + vector.x / 2].c = '*';
        map[new_y][new_x].visited = 1;
        create_path(map, new_x, new_y, size);
        map[new_y - vector.y / 2][new_x - vector.x / 2].c = '*';
        return;
    }
    return;
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
