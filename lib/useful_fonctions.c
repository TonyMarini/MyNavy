/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** useful_fonctions
*/

#include "include/function.h"

int my_strisnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int my_strlen(char *str)
{
    int size = 0;

    while (str[size] != '\0')
        size++;
    return (size);
}