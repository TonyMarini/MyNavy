/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** navy
*/

#ifndef __NAVY_H__
#define __NAVY_H__

#include "navy2.h"

int main(int ac, char **av);
int input_processing(int ac, char **av);
int display_help(void);
int start_player_one(char *filepath);
int start_player_two(char *pid, char *filepath);
int error_input_processing(void);
char **error_filepath(int *);
int error_position_ships(void);
int error_pid(void);
int error_colision_ships(void);
char **load_ships(char *filepath, int *status);
char **load_map(char **ships, int *status);
int navy(int pid_enemy, char **map_user, char **map_enemy, int user);
char **stuff_coord(int *fd, int *status, char **ships);
int verification_coord(char **ships);
int check_size_ship(char *ship);
int check_size_x(char *x, char *xt, int *size);
int check_size_y(char *y, char *yt, int *size);
int verification_size_ships(char **ships);
int connection_player_one(char **map);
int connection_player_two(int pid_nb, char **map);
char get_position_ship(char *str, int position, int type);
char **draw_vertically(char **map, char letter, int beg, int end);
char **draw_horizontally(char **map, char beg, char end , int nbr);
char **draw_the_ship(char **map, int i);
int connection_failed(void);
void sig_connection_player_two(int signal, siginfo_t *siginfo, void *txt);
int verification_input(char *command);

#endif
