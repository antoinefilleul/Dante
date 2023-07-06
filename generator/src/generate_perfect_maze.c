/*
** EPITECH PROJECT, 2023
** generate a maze
** File description:
** generate a not perfect maze
*/

#include "maze.h"
#include "directions.h"
#include "dante_generator.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int count_cols(char **uncompleted_maze)
{
    int count = 0;
    for (int i = 0; uncompleted_maze[0][i] != '\0'; i += 1) {
        count += 1;
    }
    return count;
}

int count_rows(char **uncompleted_maze)
{
    int count = 0;
    for (int i = 0; uncompleted_maze[i] != NULL; i += 1) {
        count += 1;
    }
    return count;
}

int possible_movement(int **all_directions, char **uncompleted_maze, int i,
int *current)
{
    int nb_cols = count_cols(uncompleted_maze);
    int nb_rows = count_rows(uncompleted_maze);
    if ((((current[1] + all_directions[i][1]) >= 0 && (current[1] +
    all_directions[i][1]) < nb_rows) && ((current[0] + all_directions[i][0])
    >= 0 && (current[0] + all_directions[i][0]) < nb_cols) && ((current[1] +
    (all_directions[i][1] * 2)) >= 0 && ((current[1] + (all_directions[i][1] *
    2)) < nb_rows) && ((current[0] + (all_directions[i][0] * 2)) >= 0 &&
    ((current[0] + (all_directions[i][0] * 2)) < nb_cols))))) {
        if ((uncompleted_maze[current[1] + all_directions[i][1]][current[0] +
        all_directions[i][0]] == 'X' && uncompleted_maze[current[1] +
        (all_directions[i][1] * 2)][current[0] + (all_directions[i][0] * 2)] ==
        'X')) {
        return true;
        }
    }
    return false;
}

void generate_perfect_maze(char **uncompleted_maze,
int **all_directions, int x, int y)
{
    int current[2] = {x, y};
    random_directions(all_directions);
    for (int i = 0; i < 4; i += 1) {
        if (possible_movement(all_directions, uncompleted_maze, i, current) ==
        true) {
            uncompleted_maze[(current[1] + all_directions[i][1])][(current[0]
            + all_directions[i][0])] = '*';
            uncompleted_maze[(current[1] + (all_directions[i][1] * 2))]
            [(current[0] + (all_directions[i][0] * 2))] = '*';
            current[1] = (current[1] + (all_directions[i][1] * 2));
            current[0] = (current[0] + (all_directions[i][0] * 2));
            generate_perfect_maze(uncompleted_maze, all_directions, current[0],
            current[1]);
        }
    }
}
