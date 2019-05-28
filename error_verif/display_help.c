/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** display_help
*/

#include "navy.h"

int display_help(void)
{
    write(1, "USAGE\n     ./navy [first_player_pid] navy_positions\n", 52);
    write(1, "DESCRIPTION\n     first_player_pid:  only for the 2nd", 52);
    write(1, " player.  pid of the first player.\n     navy_positions:", 55);
    write(1, " file representing the positions of the ships.\n", 47);
    return (0);
}