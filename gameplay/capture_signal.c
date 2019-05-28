/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** capture_signal
*/

#include "navy.h"

int count_the_sig(int nb, int status)
{
    static int count = 0;

    if (status == 1)
        count = 0;
    count += nb;
    return (count);
}