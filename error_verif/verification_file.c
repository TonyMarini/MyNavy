/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** verification_file
*/

#include "navy.h"

int check_size_x(char *x, char *xt, int *size)
{
    if (*x + *size != *xt && *x - *size != *xt)
        return (0);
    return (1);
}

int check_size_y(char *y, char *yt, int *size)
{
    if (*y + *size != *yt && *y - *size != *yt)
        return (0);
    return (1);
}

int check_size_ship(char *ship)
{
    int size_ship = ship[0] - 49;
    char x = ship[2];
    char y = ship[3];
    char xt = ship[5];
    char yt = ship[6];

    if ((x != xt && y != yt) || (x == xt && y == yt))
        return (0);
    if (x != xt)
        return (check_size_x(&x, &xt, &size_ship));
    else
        return (check_size_y(&y, &yt, &size_ship));
}

int verification_ship(char *ship)
{
    if (ship[1] != ':' || ship[4] != ':')
        return (0);
    if (ship[2] < 'A' || ship[2] > 'H')
        return (0);
    if (ship[3] < '1' || ship[3] > '8')
        return (0);
    if (ship[5] < 'A' || ship[5] > 'H')
        return (0);
    if (ship[6] < '1' || ship[6] > '8')
        return (0);
    if (ship[7] != '\0')
        return (0);
    return (check_size_ship(ship));
}

int verification_coord(char **ships)
{
    if (verification_size_ships(ships) != 1111)
        return (0);
    for (int i = 0; i < 4; i++) {
        if (verification_ship(ships[i]) == 0)
            return (0);
    }
    return (1);
}