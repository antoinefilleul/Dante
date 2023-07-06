/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-bsdante-antoine.filleul
** File description:
** dante
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>

#ifndef DANTE_H_
    #define DANTE_H_
    typedef struct path_s {
        struct path_s *next;
        struct path_s *prev;
        int **past;
        float dist_end;
        float dist_start;
        float cost;
        int x;
        int y;
    } path_t;

    typedef struct save_s {
        struct save_s *next;
        int x;
        int y;
    } save_t;

    typedef struct struct_list_s {
        path_t *list_open;
        save_t *list_close;
    } struct_list_t;

    typedef struct map_s {
        char **map;
        int endx;
        int endy;
    } map_t;
#endif /* !DANTE_H_ */
