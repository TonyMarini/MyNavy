/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** hit_or_miss
*/

#include "navy.h"

int manage_lose_hit_miss(char *command, char **map)
{
    if (hit_or_miss(command, map) == 1)
        map_hit_or_miss(1, map, command);
    else
        map_hit_or_miss(0, map, command);
}

int hit_or_miss(char *command, char **map_user)
{
    struct sigaction signal1;
    struct sigaction signal2;
    int sig = 0;

    signal1.sa_sigaction = &signal_play;
    signal2.sa_sigaction = &signal_stop;
    sigaction(SIGUSR1, &signal1, NULL);
    sigaction(SIGUSR2, &signal2, NULL);
    pause();
    write(1, command, 2);
    sig = count_the_sig(0, 0);
    if (sig == 1 && verification_command(command, map_user) != 0) {
        write(1, ": hit\n", 6);
        return (1);
    }
    write(1, ": missed\n", 9);
    return (0);
}

void send_hit_or_miss(char **map_user, char *x, char *y, int *pid_enemy)
{
    if (translate_coord(map_user, *x, *y) == 1) {
        usleep(1000);
        kill(*pid_enemy, SIGUSR1);
    } else {
        usleep(1000);
        kill(*pid_enemy, SIGUSR2);
    }
}

void change_turn(int *turn, char **map_user, char **map_enemy)
{
    if (*turn == 2)
        *turn = 4;
    else if (*turn == 4)
        *turn = 2;
    if (*turn == 1)
        *turn = 3;
    else if (*turn == 3) {
        *turn = 1;
        print_map_players(map_user, map_enemy, turn);
    }
}
