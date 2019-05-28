/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** ennemies_map
*/

#include "navy.h"

int enemy_map(pid_t pid_enemy, char **map_user, int user)
{
    char **en_map = NULL;
    int line = 2;
    int cols = 2;

    en_map = create_map();
    en_map = fill_map(en_map);
    en_map = map_plan(en_map);
    put_the_dots(en_map);
    return (navy(pid_enemy, map_user, en_map, user));
}