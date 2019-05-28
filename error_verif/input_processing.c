/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** input_processing
*/

#include "navy.h"

int input_processing(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (display_help());
    if (ac == 2) {
        return (start_player_one(av[1]));
    } else if (ac == 3) {
        return (start_player_two(av[1], av[2]));
    } else
        return (error_input_processing());
}