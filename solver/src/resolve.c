/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-bsdante-antoine.filleul
** File description:
** resolve
*/

#include "dante.h"
char **create_map(char const *map);
int look_right(struct_list_t *struct_list, map_t *map);
int look_left(struct_list_t *struct_list, map_t *map);
int look_up(struct_list_t *struct_list, map_t *map);
int look_down(struct_list_t *struct_list, map_t *map);
int release_head(struct_list_t *structlist);
struct_list_t *create_heads(int endx, int endy);
int display(struct_list_t *struct_list, map_t *map_struct);

int sizex(char **map)
{
    int i = 0;
    for (; map[0][i] != '\0'; i++) {}
    return i;
}

int sizey(char **map)
{
    int i = 0;
    for (; map[i] != NULL; i++) {}
    return i;
}

int look_around(struct_list_t *struct_list, map_t *map)
{
    if (look_right(struct_list, map) == 2)
        return 0;
    if (look_left(struct_list, map) == 2)
        return 0;
    if (look_down(struct_list, map) == 2)
        return 0;
    if (look_up(struct_list, map) == 2)
        return 0;
    return 1;
}

int find(struct_list_t *struct_list, map_t *map)
{
    while (struct_list->list_open != NULL) {
        if (look_around(struct_list, map) == 0)
            return 0;
        if (release_head(struct_list) == 1)
            return 2;
    }
    return 1;
}

int main(int argc, char const *const *argv)
{
    if (argc != 2)return 84;
    char **map = create_map(argv[1]);
    if (map == NULL)return 84;
    map_t *map_struct = malloc(sizeof(map_t));
    if (map_struct == NULL)return 84;
    map_struct->endx = sizex(map) - 1;
    map_struct->endy = sizey(map) - 1;
    map_struct->map = map;
    struct_list_t *struct_list =
    create_heads(map_struct->endx, map_struct->endy);
    if (struct_list == NULL)return 84;
    if (find(struct_list, map_struct) == 2) {
        printf("no solution found");
        return 84;
    }
    if (display(struct_list, map_struct) == 84)return 84;
    return 0;
}
