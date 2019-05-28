/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** action_error_two
*/

#include "navy.h"

int connection_failed(void)
{
    write(1, "\nconnection failed\n", 19);
    return (84);
}