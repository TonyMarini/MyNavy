/*
** EPITECH PROJECT, 2018
** get_next_line.h
** File description:
** header
*/

#ifndef READ_SIZE
#define READ_SIZE (1)
#endif

#define VERIF_MALLOC(str) if ((str) == NULL) return (NULL);

#ifndef __GET_NEXT_LINE_H__
#define __GET_NEXT_LINE_H__

char *get_next_line(int);
char *stuff_line(char *, char *, int *, int *);
char *save_buffer(char *, char *, int *);
char *check_save(char *, char *, int *, int *);
int end_line(int *, char *, int, char *);

#endif
