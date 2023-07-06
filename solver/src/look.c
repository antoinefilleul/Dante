/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-killian.trouve
** File description:
** look
*/
#include "dante.h"
int create_new_node(map_t *map, path_t *list_open, int x, int y);
int create_new_save(struct_list_t *structli, int x, int y);

int check_save(int x, int y, struct_list_t *struct_list)
{
    save_t *temp = struct_list->list_close;
    while (temp != NULL) {
        if (temp->x == x && temp->y == y) {
            return 1;
    }
        temp = temp->next;
    }
    return 0;
}

int look_right(struct_list_t *struct_list, map_t *map)
{
    int x = struct_list->list_open->x + 1;
    if (x > map->endx)
        return -1;
    if (map->map[struct_list->list_open->y][x] != '*')
        return -1;
    if (check_save(x, struct_list->list_open->y, struct_list) == 1)
        return -1;
    if (x == map->endx && struct_list->list_open->y == map->endy)
        return 2;
    if (create_new_save(struct_list, x, struct_list->list_open->y) == 84)
        exit(84);
    if (create_new_node(map, struct_list->list_open, x,
    struct_list->list_open->y) == 84)
        exit(84);
    return 0;
}

int look_left(struct_list_t *struct_list, map_t *map)
{
    int x = struct_list->list_open->x - 1;
    if (x < 0)
        return -1;
    if (map->map[struct_list->list_open->y][x] != '*')
        return -1;
    if (check_save(x, struct_list->list_open->y, struct_list) == 1)
        return -1;
    if (x == map->endx && struct_list->list_open->y == map->endy)
        return 2;
    if (create_new_save(struct_list, x, struct_list->list_open->y) == 84)
        exit(84);
    if (create_new_node(map, struct_list->list_open, x,
    struct_list->list_open->y) == 84)
        exit(84);
    return 0;
}

int look_down(struct_list_t *struct_list, map_t *map)
{
    int y = struct_list->list_open->y + 1;
    if (y > map->endy)
        return -1;
    if (map->map[y][struct_list->list_open->x] != '*')
        return -1;
    if (check_save(struct_list->list_open->x, y, struct_list) == 1)
        return -1;
    if (y == map->endy && struct_list->list_open->x == map->endx)
        return 2;
    if (create_new_save(struct_list, struct_list->list_open->x, y) == 84)
        exit(84);
    if (create_new_node(map, struct_list->list_open,
    struct_list->list_open->x, y) == 84)
        exit(84);
    return 0;
}

int look_up(struct_list_t *struct_list, map_t *map)
{
    int y = struct_list->list_open->y - 1;
    if (y < 0)
        return -1;
    if (map->map[y][struct_list->list_open->x] != '*')
        return -1;
    if (check_save(struct_list->list_open->x, y, struct_list) == 1)
        return -1;
    if (y == map->endy && struct_list->list_open->x == map->endx)
        return 2;
    if (create_new_save(struct_list, struct_list->list_open->x, y) == 84)
        exit(84);
    if (create_new_node(map, struct_list->list_open,
    struct_list->list_open->x, y) == 84)
        exit(84);
    return 0;
}
