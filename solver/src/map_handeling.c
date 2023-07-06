/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-killian.trouve
** File description:
** map_handeling
*/

#include <unistd.h>
#include "dante.h"
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
char **my_str_to_word_array(char const *str, char key);
int lenmap(char *buffer, char wish)
{
    int i = 0;
    int x = 0;
    int lasti = 0;
    int y = 1;
    if (buffer == NULL)
        exit(84);
    while (buffer[i] != '\0') {
        if (buffer[i] == '\n' && (i - lasti) > x)
            x = i - lasti;
        if (buffer[i] == '\n') {
            lasti = i;
            y++;
        }
        i++;
    }
    switch (wish) {
    case 'x': return x - 1; break;
    case 'y': return y; break;
    default: return 0; break;
    }
}

char **create_map(char const *map)
{
    if (access(map, F_OK) == -1)
        exit(84);
    int fd = open(map, O_RDONLY);
    if (fd == -1)
    return NULL;
    struct stat sb;
    if (stat(map, &sb) == -1)
        return NULL;
    int size = sb.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        return NULL;
    read(fd, buffer, size);
    buffer[size] = '\0';
    char **map2D = my_str_to_word_array(buffer, '\n');
    if (map2D == NULL)
        return NULL;
    return map2D;
}

int change_map(struct_list_t *struct_list, map_t *map_struct)
{
    int i = 0;
    while (struct_list->list_open->past[i] != NULL) {
        map_struct->map[struct_list->list_open->past[i][1]]
        [struct_list->list_open->past[i][0]] = 'o';
        i++;
    }
    map_struct->map[map_struct->endy][map_struct->endx] = 'o';
    return 0;
}
