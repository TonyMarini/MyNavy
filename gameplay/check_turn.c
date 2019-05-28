/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** check_turn
*/

#include "navy.h"

void check_turn(int *turn, char **map_user, char **map_enemy)
{
    if (*turn == 1)
        *turn = 3;
    else if (*turn == 3)
        *turn = 1;
    if (*turn == 2)
        *turn = 4;
    else if (*turn == 4) {
        *turn = 2;
        print_map_players(map_user, map_enemy, turn);
    }
}