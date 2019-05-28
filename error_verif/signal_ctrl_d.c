/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** signal_ctrl_d
*/

#include "navy.h"

int display_ctrl_d(void)
{
    write(1, "\n", 1);
    return (84);
}

int signal_ctrl_d(int *pid_enemy)
{
    usleep(1000);
    kill(*pid_enemy, SIGUSR2);
    return (display_ctrl_d());
}