/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-killian.trouve
** File description:
** display
*/
#include "dante.h"
#include <stdio.h>
int change_map(struct_list_t *struct_list, map_t *map_struct);

int display(struct_list_t *struct_list, map_t *map_struct)
{
    change_map(struct_list, map_struct);
    for (int i = 0; map_struct->map[i + 1] != NULL; i++) {
        if (printf("%s\n", map_struct->map[i]) == 84)return 84;
    }
    if (printf("%s", map_struct->map[map_struct->endy]) == -1)return 84;
    return 0;
}
