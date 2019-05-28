/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** start_player
*/

#include "navy.h"

int start_player_one(char *filepath)
{
    int status = 0;
    char **ships = load_ships(filepath, &status);
    char **map = NULL;

    if (status != 1 && status != 2 && ships == NULL)
        return (error_position_ships());
    else if (status == 1 || status == 2)
        return (84);
    map = load_map(ships, &status);
    if (status == 3)
        return (error_colision_ships());
    return (connection_player_one(map));
}

int start_player_two(char *pid, char *filepath)
{
    int pid_nb = 0;
    int status = 0;
    char **ships = load_ships(filepath, &status);
    char **map = NULL;

    if (my_strisnum(pid) == 0)
        return (error_pid());
    pid_nb = my_getnbr(pid);
    if (status != 1 && status != 2 && ships == NULL)
        return (error_position_ships());
    else if (status == 1 || status == 2)
        return (84);
    map = load_map(ships, &status);
    if (status == 3) {
        free(map);
        return (error_colision_ships());
    }
    return (connection_player_two(pid_nb, map));
}