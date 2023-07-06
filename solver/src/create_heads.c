/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-killian.trouve
** File description:
** create_heads
*/

#include "dante.h"

int fill_save(save_t **save, path_t *path)
{
    (*save)->next = NULL;
    (*save)->x = path->x;
    (*save)->y = path->y;
    return 0;
}

struct_list_t *createstruct(save_t *save, path_t *path, struct_list_t *stru_li)
{
    stru_li = malloc(sizeof(struct_list_t));
    if (stru_li == NULL)return NULL;
    stru_li->list_close = save;
    stru_li->list_open = path;
    return stru_li;
}

struct_list_t *create_heads(int endx, int endy)
{
    path_t *path = malloc(sizeof(path_t));
    if (path == NULL)return NULL;
    path->next = NULL;path->prev = NULL;
    path->past = malloc(sizeof(int *) * 2);
    if (path->past == NULL)return NULL;
    path->past[1] = NULL;
    path->past[0] = malloc(sizeof(int ) * 2);
    if (path->past[0] == NULL)return NULL;
    path->past[0][0] = 0;path->past[0][1] = 0;
    path->x = 0;path->y = 0;path->dist_start = 0;
    path->dist_end = sqrtf((float)(pow((double)(path->x + endx),
    (double)2) * pow((double)(path->y + endy), (double)2)));
    path->cost = path->dist_end + path->dist_start;
    save_t *save = malloc(sizeof(save_t));
    if (save == NULL)return NULL;
    fill_save(&save, path);
    struct_list_t *struct_list = NULL;
    struct_list = createstruct(save, path, struct_list);
    if (struct_list == NULL)return NULL;
    return struct_list;
}
