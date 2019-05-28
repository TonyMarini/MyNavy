/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** signal_sending
*/

#include "navy.h"

void signal_play(int signal, siginfo_t *siginfo, void *txt)
{
    count_the_sig(1, 1);
}

void signal_stop(int signal, siginfo_t *siginfo, void *txt)
{
    count_the_sig(2, 1);
}