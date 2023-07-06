/*
** EPITECH PROJECT, 2023
** setup_directions?c
** File description:
** setup all directions
*/

#include <stdlib.h>
#include "dante_generator.h"

static int sub_setup_direction(int ** all_directions)
{
    all_directions[2][0] = -1;
    all_directions[2][1] = 0;
    all_directions[3] = malloc(sizeof(int) * 2);
    if (all_directions[3] == NULL)
        return KO;
    all_directions[3][0] = 1;
    all_directions[3][1] = 0;
    return OK;
}

int setup_direction(int **all_directions)
{
    all_directions[0] = malloc(sizeof(int) * 2);
    if (all_directions[0] == NULL)
        return KO;
    all_directions[0][0] = 0;
    all_directions[0][1] = 1;
    all_directions[1] = malloc(sizeof(int) * 2);
    if (all_directions[1] == NULL)
        return KO;
    all_directions[1][0] = 0;
    all_directions[1][1] = -1;
    all_directions[2] = malloc(sizeof(int) * 2);
    if (all_directions[2] == NULL)
        return KO;
    if (sub_setup_direction(all_directions) == 84)
        return KO;
    return OK;
}
