/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** turn_player
*/

#include "get_next_line.h"
#include "navy.h"

int send_coord(char *command, int *pid_enemy)
{
    usleep(1000);
    kill(*pid_enemy, SIGUSR1);
    for (int i = 'A'; i <= command[0]; i++) {
        usleep(1000);
        kill(*pid_enemy, SIGUSR1);
    }
    usleep(1000);
    kill(*pid_enemy, SIGUSR2);
    for (int i = '1'; i <= command[1]; i++) {
        usleep(1000);
        kill(*pid_enemy, SIGUSR1);
    }
    usleep(1000);
    kill(*pid_enemy, SIGUSR2);
    return (0);
}

int player_turn_attack(char **map_user, char **map_enemy,
    int *turn, int *pid_enemy)
{
    char *command = NULL;

    if ((command = get_next_line(0)) == NULL) {
        free_all(map_user, map_enemy);
        return (signal_ctrl_d(pid_enemy));
    }
    if (verification_input(command) == 0) {
        write(1, "wrong position", 14);
        return (player_turn(map_user, map_enemy, turn, pid_enemy));
    }
    send_coord(command, pid_enemy);
    if (manage_lose_hit_miss(command, map_enemy) == 1)
        return (1);
    if (win_or_continue() == 1)
        return (display_win(map_user, map_enemy, turn));
    check_turn(turn, map_user, map_enemy);
    return (player_turn(map_user, map_enemy, turn, pid_enemy));
}

int player_turn_wait(char **map_user, char **map_enemy,
    int *turn, int *pid_enemy)
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
    if (sig == 2) {
        free_all(map_user, map_enemy);
        return (84);
    }
    else
        return (analyse_command(turn, map_user, map_enemy, pid_enemy));
}

int player_turn(char **map_user, char **map_enemy, int *turn, int *pid_enemy)
{
    display_turn_player(turn);
    if (*turn == 1 || *turn == 4)
        return (player_turn_attack(map_user, map_enemy, turn, pid_enemy));
    else
        return (player_turn_wait(map_user, map_enemy, turn, pid_enemy));
}
