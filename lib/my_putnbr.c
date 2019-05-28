/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** my put nbr
*/

#include "include/function.h"

void display_my_put_nbr(int i, int nb_modified, long divisor, int nb)
{
    char str[2] = " \0";

    if (nb < 0) {
        nb_modified = nb * -1;
        write(1, "-", 1);
    }
    while (nb_modified >= divisor) {
        divisor = divisor * 10;
        i++;
    }
    while (i != 0) {
        divisor = divisor / 10;
        str[0] = nb_modified / divisor + '0';
        write(1, &str[0], 1);
        nb_modified = nb_modified % divisor;
        i--;
    }
    str[0] = nb_modified % 10 + '0';
    write(1, &str[0], 1);
}

int my_putnbr(int nb)
{
    int nb_modified = nb;
    int i = 0;
    long divisor = 10;
    int k = 0;

    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        k = 1;
    }
    if (k == 0)
        display_my_put_nbr(i, nb_modified, divisor, nb);
    return (0);
}
