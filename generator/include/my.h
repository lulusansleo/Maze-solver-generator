/*
** EPITECH PROJECT, 2022
** Dante Star
** File description:
** myh
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    #include <stdbool.h>

typedef struct map {
    char c;
    int visited;
} map_t;

typedef struct vector {
    int x;
    int y;
} vector_t;

vector_t gen_vector(int x, int y);
map_t **generate(map_t **map, int x, int y);
void create_path(map_t **map, int x, int y);
map_t **generation(char *width, char *height);
map_t **write_grid(map_t **map, int x, int y);
map_t *write_cell_line(map_t *str, int x);
map_t *write_wall_line(map_t *str, int x);
int integer_check(char *str, char *str_sec);

#endif /* !MY_H_ */
