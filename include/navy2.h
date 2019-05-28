/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** navy2
*/

#ifndef NAVY2_H_
#define NAVY2_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include "function.h"

char **create_map(void);
char **fill_map(char **map);
char **map_plan(char **map);
int enemy_map(pid_t pid_enemy, char **map_user, int turn);
int check_lose_charactere(char *map);
int display_lose(char **map_user, char **map_enemy, int *turn);
int display_win(char **map_user, char **map_enemy, int *turn);
int display_ctrl_d(void);
int check_lose(char **map_player);
int get_pid_enemy(int pid_enemy);
int count_the_sig(int nb, int status);
int signal_ctrl_d(int *pid_enemy);
void print_map_players(char **map_user, char **map_enemy, int *turn);
void display_turn_player(int *turn);
int check_coord(char *command);
int player_turn_attack(char **map_user, char **map_enemy,
    int *turn, int *pid_enemy);
int player_turn_wait(char **map_user, char **map_enemy,
    int *turn, int *pid_enemy);
int player_turn(char **map_user, char **map_enemy, int *turn, int *pid_enemy);
int analyse_signal_stop(void);
void signal_play(int signal, siginfo_t *siginfo, void *txt);
void signal_stop(int signal, siginfo_t *siginfo, void *txt);
int send_coord(char *command, int *pid_enemy);
char **put_the_dots(char **map);
int verification_command(char *command, char **map);
int analyse_command(int *turn, char **map_user,
    char **map_enemy, int *pid_enemy);
int translate_coord(char **map, char x, char y);
void map_hit_or_miss(int status, char **map, char *command);
int hit_or_miss(char *command, char **map_user);
int manage_lose_hit_miss(char *command, char **map);
void check_turn(int *turn, char **map_user, char **map_enemy);
void change_turn(int *turn, char **map_user, char **map_enemy);
void send_hit_or_miss(char **map_user, char *x, char *y, int *pid_enemy);
int win_or_continue(void);
void free_map(char **map);
void free_all(char **map_user, char **map_enemy);

#endif
