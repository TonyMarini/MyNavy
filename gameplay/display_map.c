/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** display_map
*/

#include "navy.h"

void print_map_players(char **map_user, char **map_enemy, int *turn)
{
    write(1, "\nmy positions:\n", 15);
    for (int i = 0; i <= 9; i++) {
        write(1, map_user[i], 17);
        write(1, "\n", 1);
    }
    write(1, "\nenemy's positions:\n", 20);
    for (int i = 0; i <= 9; i++) {
        write(1, map_enemy[i], 17);
        write(1, "\n", 1);
    }
}

void display_turn_player(int *turn)
{
    if (*turn == 2 || *turn == 3)
        write(1, "\nwaiting for enemy's attack...\n", 31);
    else
        write(1, "\nattack: ", 9);
}

int check_coord(char *command)
{
    if ((command[0] < 'A' || command[0] > 'H') || (command[1] < '1'
        || command[1] > '8') || command[2] != '\0')
        return (0);
    return (1);
}
