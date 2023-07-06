/*
** EPITECH PROJECT, 2023
** print_maze
** File description:
** print the final maze
*/

#include "maze.h"
#include <unistd.h>
#include <stdio.h>
#include "dante_generator.h"

static int print_sub_maze(maze_t *maze, char **completed_maze, int i)
{
    for (int j = 0; j < maze->x; j += 1) {
        if (write(1, &completed_maze[i][j], 1) == -1)
            return KO;
    }
    if (write(1, "\n", 1) == -1)
            return KO;
    return OK;
}

int print_maze(maze_t *maze, char **completed_maze)
{
    for (int i = 0; i < (maze->y - 1); i += 1) {
        if (print_sub_maze(maze, completed_maze, i) == 84)
            return KO;
    }
    if (printf("%s", completed_maze[maze->y - 1]) < 0)
        return KO;
    return OK;
}
