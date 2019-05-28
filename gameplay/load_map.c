/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** load_map
*/

#include "navy.h"

char **create_map(void)
{
    char **map = NULL;

    if ((map = malloc(sizeof(char *) * 11)) == NULL)
        return (NULL);
    for (int i = 0; i <= 10; i++) {
        if ((map[i] = malloc(sizeof(char) * 18)) == NULL)
            return (NULL);
        map[i][17] = '\0';
    }
    map[10] = NULL;
    map[0][0] = ' ';
    return (map);
}

char **fill_map(char **map)
{
    int line  = 0;
    int cols = 1;

    while (map[line] != NULL) {
        if (line == 9 && cols == 17)
            break;
        else if (cols == 17) {
            (map[line + 1] != NULL) ? line += 1 : 0;
            cols = 0;
        }
        map[line][cols] = ' ';
        cols += 1;
    }
    for (int j = 0; map[1][j] != '\0'; j++)
        map[1][j] = '-';
    for (int i = 0; i != 10; i++)
        map[i][1] = '|';
    map[1][1] = '+';
    return (map);
}

char **map_plan(char **map)
{
    int i = 2;
    int charact = 65;

    while (map[0][i] != '\0') {
        if (i % 2 == 0) {
            map[0][i] = charact;
            charact += 1;
        }
        i++;
    }
    i = 2;
    charact = 49;
    for (; i <= 9; i++, charact++)
        map[i][0] = charact;
    return (map);
}

static char **place_the_ship(char **map, char **ship, int line, int *status)
{
    int i = my_getnbr(ship[line]);
    int check = 1;
    char x_letter = get_position_ship(ship[line], 0, 1);
    char y_letter = get_position_ship(ship[line], 3, 1);
    char x_nbr = get_position_ship(ship[line], 0, 2);
    char y_nbr = get_position_ship(ship[line], 3, 2);

    while (check <= i && *status != 3) {
        if (x_letter == y_letter)
            map = draw_vertically(map, x_letter, x_nbr, y_nbr);
        else
            map = draw_horizontally(map, x_letter, y_letter, x_nbr);
        if (map == NULL)
            *status = 3;
        check++;
    }
    if (map == NULL)
        return (NULL);
    map = draw_the_ship(map, i);
    return (map);
}

char **load_map(char **ships, int *status)
{
    char **map = create_map();
    int line = 2;
    int cols = 2;

    map = fill_map(map);
    map = map_plan(map);
    put_the_dots(map);
    for (int i = 0; i <= 3; i++)
        if ((map = place_the_ship(map, ships, i, status)) == NULL) {
            return (NULL);
        }
    return (map);
}
