/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** load_ships
*/

#include "navy.h"
#include "get_next_line.h"

char **stuff_coord(int *fd, int *status, char **ships)
{
    int i = 0;

    while (*status != 2 && ((ships[i] = get_next_line(*fd))) != NULL) {
        if (ships[i] == NULL)
            *status = 2;
        i++;
    }
    if (i == 0) {
        *status = -1;
        return (NULL);
    }
    ships[i] = NULL;
    if (i != 4)
        return (NULL);
    return (ships);
}

char **load_ships(char *filepath, int *status)
{
    int fd = 0;
    char **ships = malloc(sizeof(char *) * 5);

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (error_filepath(status));
    if (ships == NULL)
        *status = 2;
    ships = stuff_coord(&fd, status, ships);
    if (*status == -1)
        return (error_filepath(status));
    if (*status != 2 && verification_coord(ships) == 0)
        return (NULL);
    close(fd);
    return (ships);
}

int verification_size_ships(char **ships)
{
    int k = 0;
    int size = 0;

    if (ships == NULL)
        return (k);
    for (int i = 0; i < 4 && ships[i] != NULL; i++) {
        if ((size = my_strlen(ships[i])) != 7)
            return (0);
        if (ships[i][0] == '2')
            k += 1;
        if (ships[i][0] == '3')
            k += 10;
        if (ships[i][0] == '4')
            k += 100;
        if (ships[i][0] == '5')
            k += 1000;
    }
    return (k);
}
