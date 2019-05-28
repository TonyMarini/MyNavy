/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** get_position_ship
*/

#include "navy.h"

char **put_the_dots(char **map)
{
    int line = 2;
    int cols = 2;

    while (line <= 9) {
        if (line == 9 && cols == 17)
            break;
        else if (cols == 17) {
            line += 1;
            cols = 2;
        }
        if (cols % 2 == 0)
            map[line][cols] = '.';
        cols++;
    }
    return (map);
}

char get_position_ship(char *str, int position, int type)
{
    char letter;

    while (str[position] != ':')
        position += 1;
    if (type == 1)
        letter = str[position + 1];
    else if (type == 2)
        letter = str[position + 2];
    return (letter);
}

char **draw_vertically(char **map, char letter, int beg, int end)
{
    int x = 0;
    int y_beg = 0;
    int y_end = 0;

    while (map[0][x] != letter)
        x++;
    while (map[y_beg][0] != beg)
        y_beg++;
    while (map[y_end][0] != end)
        y_end++;
    while (y_beg <= y_end) {
        if (map[y_beg][x] >= '2' && map[y_beg][x] <= '5') {
            free_map(map);
            return (NULL);
        }
        map[y_beg][x] = '&';
        y_beg += 1;
    }
    return (map);
}

char **draw_horizontally(char **map, char beg, char end, int nbr)
{
    int y = 0;
    int x_beg = 0;
    int x_end = 0;
    int i = 0;

    while (map[y][0] != nbr)
        y++;
    while (map[0][x_beg] != beg)
        x_beg++;
    while (map[0][x_end] != end)
        x_end++;
    i = x_beg;
    while (x_beg <= x_end) {
        if (x_beg % 2 == 0 && (map[y][x_beg] >= '2' && map[y][x_beg] <= '5'))
            return (NULL);
        if (x_beg % 2 == 0)
            map[y][x_beg] = '&';
        x_beg += 1;
    }
    return (map);
}

char **draw_the_ship(char **map, int i)
{
    int line = 2;
    int cols = 2;

    while (line <= 9) {
        if (cols == 17 && line == 9)
            break;
        else if (cols == 17) {
            line += 1;
            cols = 2;
        }
        if (map[line][cols] == '&')
            map[line][cols] = i + 48;
        cols++;
    }
    return (map);
}