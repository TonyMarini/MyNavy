/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** check_lose
*/

#include "navy.h"

int display_lose(char **map_user, char **map_enemy, int *turn)
{
    print_map_players(map_user, map_enemy, turn);
    write(1, "\nEnemy won\n", 11);
    return (1);
}

int display_win(char **map_user, char **map_enemy, int *turn)
{
    print_map_players(map_user, map_enemy, turn);
    free_all(map_user, map_enemy);
    write(1, "\nI won\n", 7);
    return (0);
}

int check_lose(char **map_player)
{
    int status = 0;
    int line = 2;
    int cols = 2;

    while (line <= 9) {
        if (line == 9 && cols == 17) {
            status = 1;
            break;
        } else if (cols == 17) {
            line += 1;
            cols = 2;
        }
        if (map_player[line][cols] >= '1' && map_player[line][cols] <= '5')
            return (1);
        cols++;
    }
    if (status == 1)
        return (0);
    return (1);
}