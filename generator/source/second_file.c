/*
** EPITECH PROJECT, 2023
** dantes star
** File description:
** generator
*/

#include "my.h"

map_t **generate(map_t **map, int x, int y)
{
    for (int i = 0; i < y - 2 || i + 1 < y - 2; i += 2) {
        for (int j = 0; j < x - 2 || j + 1 < x - 2; j += 2) {
            create_path(map, j, i);
        }
    }
    return map;
}

void create_path(map_t **map, int x, int y)
{
    vector_t vector = gen_vector(x, y);
    if (map[y][x].visited == 0) {
        map[y][x].visited = 1;
        while (check_visit(map, x, y)) {
            map[y + vector.y / 2][x + vector.x / 2].c = '*';
            printf("x = %d, y = %d, c = %c\n",x + vector.x, y + vector.y, map[y + vector.y][x + vector.x].c);
            x += vector.x;
            y += vector.y;
            map[y][x].visited = 1;
            vector = gen_vector(x, y);
            for (int i = 0; map[i] != NULL; i++) {
                for (int j = 0; map[i][j].c != '\0'; j++)
                    printf("%c", map[i][j].c);
                printf("\n");
            }
        }
    }
}

int check_visit(map_t **map, int x, int y)
{
    if (x - 1 < 10 ||
    map[x + 2][y].visited == 0)
        return 1;
    if (x + 1 > 0 ||
    map[x - 2][y].visited == 0)
        return 1;
    if (y + 1 > 0 ||
    map[x][y - 2].visited == 0)
        return 1;
    if (y - 1 < 10 ||
    map[x][y + 2].visited == 0)
        return 1;
    return 0;
}

vector_t gen_vector(int x, int y)
{
    int a = rand() % 2;
    int b = rand() % 2;
    int c = 2;
    vector_t vector = {0, 0};

    if (a == 0)
        c = -c;
    if (b == 0)
        vector.x = c * 1;
    else
        vector.y = c * 1;
    if (x + vector.x < 0 || x + vector.x > 20)
        vector.x = -vector.x;
    if (y + vector.y < 0 || y + vector.y > 20)
        vector.y = -vector.y;
    return vector;
}
