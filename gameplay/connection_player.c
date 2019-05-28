/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** connection_player
*/

#include "navy.h"

int get_pid_enemy(int pid_enemy)
{
    static int pid = 0;

    pid += pid_enemy;
    return (pid);
}

void sig_connection_player_one(int signal, siginfo_t *siginfo, void *txt)
{
    get_pid_enemy(siginfo->si_pid);
    write(1, "enemy connected\n", 16);
}

int connection_player_one(char **map)
{
    pid_t pid_user = getpid();
    pid_t pid_enemy = 0;
    struct sigaction signal;

    signal.sa_sigaction = &sig_connection_player_one;
    signal.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &signal, NULL);
    write(1, "my_pid: ", 8);
    my_putnbr(pid_user);
    write(1, "\nwaiting for enemy connection...\n\n", 34);
    pause();
    pid_enemy = get_pid_enemy(0);
    return (enemy_map(pid_enemy, map, 1));
}

int connection_player_two(int pid_nb, char **map)
{
    pid_t pid_user = getpid();
    pid_t pid_enemy = pid_nb;

    write(1, "my_pid: ", 8);
    my_putnbr(pid_user);
    usleep(1000);
    if (kill(pid_enemy, SIGUSR1) == -1) {
        free_map(map);
        return (connection_failed());
    }
    write(1, "\nsuccessfully connected\n", 24);
    return (enemy_map(pid_enemy, map, 2));
}
