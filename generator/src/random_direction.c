/*
** EPITECH PROJECT, 2023
** random directions generator
** File description:
** random directions generator
*/

#include "directions.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void random_directions(int **all_directions)
{
    for (int i = 0; i != 4; i += 1) {
        int shuffle = rand() % 4;
        int *stored_value = all_directions[i];
        all_directions[i] = all_directions[shuffle];
        all_directions[shuffle] = stored_value;
    }
}
