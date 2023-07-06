/*
** EPITECH PROJECT, 2023
** my_scripts
** File description:
** main
*/

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "maze.h"
#include "dante_generator.h"

int init_maze(maze_t *maze, char **argv)
{
    if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
        return KO;
    maze->x = atoi(argv[1]);
    maze->y = atoi(argv[2]);
    return OK;
}

int perfect_setup(maze_t *maze)
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
    if (print_maze(maze, uncompleted_maze) == 84)
        return KO;
    return OK;
}

int main(int argc, char **argv)
{
    if (argc != 3 && strcmp(argv[3], "perfect") != 0) {
        return KO;
    }
    maze_t *maze = malloc(sizeof(maze_t));
    if (maze == NULL)
        return KO;
    init_maze(maze, argv);
    if (maze->x <= 0 || maze->y <= 0)
        return KO;
    if (argc == 4 && strcmp(argv[3], "perfect") == 0) {
        if (perfect_setup(maze) == 84)
            return KO;
    } else {
        if (imperfect_setup(maze, maze->x, maze->y) == 84)
            return KO;
    }
    return OK;
}
