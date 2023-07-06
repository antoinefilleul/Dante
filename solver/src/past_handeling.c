/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-killian.trouve
** File description:
** past_handeling
*/
#include "dante.h"
#include <stdlib.h>

int len_int_str(int **suite)
{
    int i = 0;
    for (; suite[i] != NULL; i++);
    return i;
}

int *copy_int_str(int *n)
{
    int *new_n = malloc(sizeof(int) * 2);
    if (new_n == NULL)return NULL;
    new_n[0] = n[0];
    new_n[1] = n[1];
    return new_n;
}

int **recreate_past(path_t *list_open, int x, int y)
{
    int len = len_int_str(list_open->past);
    int **new_past = malloc(sizeof(int *) * (len + 2));
    if (new_past == NULL)return NULL;
    for (int i = 0; list_open->past[i] != NULL; i++) {
        new_past[i] = copy_int_str(list_open->past[i]);
        if (new_past[i] == NULL)return NULL;
    }
    new_past[len] = malloc(sizeof(int) * 2);
    if (new_past[len] == NULL)return NULL;
    new_past[len][0] = x;
    new_past[len][1] = y;
    new_past[len + 1] = NULL;
    return new_past;
}
