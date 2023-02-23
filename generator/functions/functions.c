/*
** EPITECH PROJECT, 2022
** Dante Star
** File description:
** utility functions
*/

#include "../include/my.h"

int integer_check(char *str, char *str_sec)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return 1;
    for (int j = 0; str_sec[j] != '\0'; j++)
        if (!isdigit(str_sec[j]))
            return 1;
    return 0;
}
