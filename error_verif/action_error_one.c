/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** action_error_one
*/

#include "navy.h"

int error_input_processing(void)
{
    write(1, "Try \"-h\" to get more information.\n", 34);
    return (84);
}

char **error_filepath(int *status)
{
    *status = 1;
    write(1, "The file doesn't exist.\n", 24);
    return (NULL);
}

int error_position_ships(void)
{
    write(1, "The position of ships must be \"LENGTH : FIRST_SQUARE ", 53);
    write(1, ": LAST_SQUARE\".\n", 16);
    return (84);
}

int error_pid(void)
{
    write(1, "Please enter a valide pid.\n", 27);
    return (84);
}

int error_colision_ships(void)
{
    write(1, "The ships are superimposed.\n", 28);
    return (84);
}