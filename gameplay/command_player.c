/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** command_player
*/

#include "navy.h"

char count_nb_sig(void)
{
    int sig = 0;
    char x = 0;

    while (sig != 2) {
        x++;
        pause();
        sig = count_the_sig(0, 0);
    }
    return (x);
}

int win_or_continue(void)
{
    struct sigaction signal1;
    struct sigaction signal2;
    int sig = 0;
    int status = 0;

    signal1.sa_sigaction = &signal_play;
    signal2.sa_sigaction = &signal_stop;
    sigaction(SIGUSR1, &signal1, NULL);
    sigaction(SIGUSR2, &signal2, NULL);
    pause();
    sig = count_the_sig(0, 0);
    if (sig == 2)
        return (1);
    else
        return (0);
}

int analyse_command(int *turn, char **map_user,
    char **map_enemy, int *pid_enemy)
{
    struct sigaction signal1;
    struct sigaction signal2;
    char x = 0;
    char y = 0;

    signal1.sa_sigaction = &signal_play;
    signal2.sa_sigaction = &signal_stop;
    x = count_nb_sig();
    y = count_nb_sig();
    send_hit_or_miss(map_user, &x, &y, pid_enemy);
    change_turn(turn, map_user, map_enemy);
    if (check_lose(map_user) == 0) {
        usleep(1000);
        kill(*pid_enemy, SIGUSR2);
        return (display_lose(map_user, map_enemy, turn));
    } else {
        usleep(1000);
        kill(*pid_enemy, SIGUSR1);
    }
    return (player_turn(map_user, map_enemy, turn, pid_enemy));
}

int verification_command(char *command, char **map)
{
    if (map[(command[1] - 48) + 1][(command[0] - 64) * 2] == 'x'
        || map[(command[1] - 48) + 1][(command[0] - 64) * 2] == 'o')
        return (0);
    return (1);
}

int verification_input(char *command)
{
    if (command[0] < 'A' || command[0] > 'H'
        || command[1] < '1' || command[1] > '8' || command[2] != '\0')
        return (0);
    return (1);
}