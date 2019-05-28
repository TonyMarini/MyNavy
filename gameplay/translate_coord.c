/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** translate_coord
*/

#include "navy.h"

int translate_coord(char **map, char x, char y)
{
    int letter = 2 * (x - 1);
    int nbr = y;

    x += 63;
    y += 47;
    if (map[nbr][letter] != '.' && map[nbr][letter] != 'o') {
        write(1, &x, 1);
        write(1, &y, 1);
        write(1, ": hit\n", 6);
        map[nbr][letter] = 'x';
        return (1);
    }
    else {
        write(1, &x, 1);
        write(1, &y, 1);
        write(1, ": missed\n", 9);
        map[nbr][letter] = 'o';
        return (0);
    }
}

void map_hit_or_miss(int status, char **map, char *command)
{
    if (status == 1)
        map[(command[1] - 48) + 1][(command[0] - 64) * 2] = 'x';
    if (status == 0)
        map[(command[1] - 48) + 1][(command[0] - 64) * 2] = 'o';
}
