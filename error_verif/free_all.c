/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** free_all
*/

#include "navy.h"

void free_map(char **map)
{
    for (int i = 0; i < 10; i++)
        free(map[i]);
    free(map);
}

void free_all(char **map_user, char **map_enemy)
{
    free_map(map_user);
    free_map(map_enemy);
}