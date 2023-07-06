/*
** EPITECH PROJECT, 2023
** generate_imperfect maze
** File description:
** generate a perfect maze but remove some walls from it
*/

#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "dante_generator.h"
#include "maze.h"

void verify_is_x(char **uncompleted_maze, int i, int j, int *count)
{
    if (uncompleted_maze[i][j] == 'X')
        (*count) += 1;
}

int count_nb_x(char **uncompleted_maze)
{
    int count = 0;
    for (int i = 0; uncompleted_maze[i] != NULL; i += 1) {
        for (int j = 0; uncompleted_maze[i][j] != '\0'; j += 1) {
            verify_is_x(uncompleted_maze, i, j, &count);
        }
    }
    return count;
}

void randomly_break_walls(char **uncompleted_maze, int x, int y)
{
    int nb_walls = count_nb_x(uncompleted_maze);
    if (nb_walls <= 10)
        return;
    int wall_disappear = nb_walls / 10;
    while (wall_disappear != 0) {
        int wall_x = rand() % y;
        int wall_y = rand() % x;
        if (uncompleted_maze[wall_x][wall_y] == 'X') {
            uncompleted_maze[wall_x][wall_y] = '*';
            wall_disappear -= 1;
        }
    }
}

int imperfect_setup(maze_t *maze, int x, int y)
{
    char **uncompleted_maze = fill_maze_with_walls(maze);
    if (uncompleted_maze == NULL)
        return KO;
    int **all_directions = malloc(sizeof(int *) * 4);
    if (all_directions == NULL)
        return KO;
    if (setup_direction(all_directions) == 84)
        return KO;
    srand(time(NULL));
    uncompleted_maze[0][0] = '*';
    generate_perfect_maze(uncompleted_maze, all_directions, 0, 0);
    uncompleted_maze[maze->y - 1][maze->x - 1] = '*';
    if (maze->y != 1 && maze->x != 1)
        uncompleted_maze[maze->y - 1][maze->x - 2] = '*';
    randomly_break_walls(uncompleted_maze, x, y);
    if (print_maze(maze, uncompleted_maze) == 84)
        return KO;
    return OK;
}
