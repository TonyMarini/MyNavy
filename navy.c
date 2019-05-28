/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** navy
*/

#include "navy.h"
#include "get_next_line.h"

int navy(int pid_enemy, char **map_user, char **map_enemy, int turn)
{
    int status = 0;
    int check = 0;

    print_map_players(map_user, map_enemy, &turn);
    return (player_turn(map_user, map_enemy, &turn, &pid_enemy));
}