/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-killian.trouve
** File description:
** createnewnode
*/

#include "dante.h"
#include <stdlib.h>
int fill_save(save_t **save, path_t *path);
int **recreate_past(path_t *list_open, int x, int y);

int place_new_node(path_t **list_open, path_t *new_node)
{
    path_t *temp = (*list_open)->next;
    path_t *prev = *list_open;
    while (temp != NULL) {
        if (new_node->cost < temp->cost) {
            new_node->prev = temp->prev;
            new_node->next = temp;
            temp->prev->next = new_node;
            temp->prev = new_node;
            return 0;
        }
        temp = temp->next;
        prev = prev->next;
    }
    new_node->next = NULL;
    new_node->prev = prev;
    prev->next = new_node;
    return 0;
}

int create_new_node(map_t *map, path_t *list_open, int x, int y)
{
    path_t *new_node = malloc(sizeof(path_t));
    if (new_node == NULL)return 84;
    new_node->dist_end = sqrtf( (float)(pow((double)(map->endx - x),
    (double)2) * pow((double)(map->endy - y), (double)2)));
    new_node->dist_start = list_open->dist_start + 1;
    new_node->cost = new_node->dist_end + new_node->dist_start;
    new_node->x = x;
    new_node->y = y;
    new_node->past = recreate_past(list_open, x, y);
    if (new_node->past == NULL)return 84;
    place_new_node(&list_open, new_node);
    return 0;
}

int create_new_save(struct_list_t *structli, int x, int y)
{
    save_t *temp = structli->list_close;
    save_t *newsave = malloc(sizeof(save_t));
    if (newsave == NULL)return 84;
    newsave->x = x;
    newsave->y = y;
    structli->list_close = newsave;
    newsave->next = temp;
    return 0;
}

int release_head(struct_list_t *structlist)
{
    path_t *temp = structlist->list_open->next;
    if (temp == NULL) {
        return 1;
    }
    structlist->list_open = temp;
    free(temp->prev);
    temp->prev = NULL;
    return 0;
}
