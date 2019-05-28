/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get next line
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/get_next_line.h"

char *stuff_line(char *line, char *buffer, int *loc, int *status)
{
    char *save = malloc(sizeof(char) * (READ_SIZE + 1 + *loc));
    int j = 0;

    for (int i = 0; i < *loc; i++)
        save[i] = line[i];
    free(line);
    VERIF_MALLOC(line = malloc(sizeof(char) * (READ_SIZE + 1 + *loc)));
    for (int i = 0; i < *loc; i++)
        line[i] = save[i];
    free(save);
    for (j = 0; j < READ_SIZE && buffer[j] != '\0' && buffer[j] != '\n'; j++) {
        line[*loc] = buffer[j];
        (*loc)++;
    }
    if (buffer[j] == '\n')
        *status = 1;
    line[*loc] = '\0';
    for (int i = 0; *status != 1 && i < READ_SIZE; i++)
        buffer[i] = '\0';
    return (line);
}

char *save_buffer(char *buffer, char *save, int *loc)
{
    int i = 0;
    int j = 0;
    float result = 0;

    result = (*loc + 1) / READ_SIZE != -1;
    if (result == -1)
        return (NULL);
    VERIF_MALLOC(save = malloc(sizeof(char) * (READ_SIZE + 1)));
    while (buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    i++;
    for (j = 0; i < READ_SIZE; j++) {
        save[j] = buffer[i];
        i++;
    }
    save[j] = '\0';
    return (save);
}

char *check_save(char *save, char *line, int *loc, int *status)
{
    int i = 0;
    int j = 0;
    int yes = 0;

    for (i = 0; save[i] != '\0' && save[i] != '\n'; i++) {
        line[*loc] = save[i];
        (*loc)++;
    }
    line[*loc] = '\0';
    i++;
    for (j = 0; i < READ_SIZE && save[i - 1] != '\0'; j++) {
        if (save[i] == '\0' || save[i] == '\n')
            yes = 1;
        save[j] = save[i];
        i++;
    }
    save[j] = '\0';
    if (yes == 1)
        *status = 2;
    return (line);
}

int end_line(int *yes, char *line, int fd, char *buffer)
{
    if (fd > 0 && *yes == 1 && line[0] != '\0') {
        *yes = 0;
        return (1);
    } else
        return (0);
}

char *get_next_line(int fd)
{
    char *line = malloc(sizeof(char) * (READ_SIZE + 1));
    char buffer[READ_SIZE] = "\0";
    static char *save = NULL;
    int loc = 0;
    int status = 0;
    static int yes = 1;

    if (save != NULL) {
        line = check_save(save, line, &loc, &status);
        if (status == 2)
            return (line);
    }
    while (status == 0) {
        if (read(fd, buffer, READ_SIZE) <= 0)
            return ((end_line(&yes, line, fd, buffer) == 1) ? line : NULL);
        line = stuff_line(line, buffer, &loc, &status);
    }
    save = save_buffer(buffer, save, &loc);
    return (fd < 0 ? NULL : line);
}
