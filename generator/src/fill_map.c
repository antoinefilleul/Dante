/*
** EPITECH PROJECT, 2023
** fill_map.c
** File description:
** fill all char in the map with 'X'
*/

#include <stddef.h>
#include <stdlib.h>
#include "maze.h"

char **fill_maze_with_walls(maze_t *maze)
{
    char **uncompleted_maze = malloc(sizeof(char *) * (maze->y + 1));
    if (uncompleted_maze == NULL)
        return NULL;
    uncompleted_maze[maze->y] = NULL;
    for (int i = 0; i < maze->y; i += 1) {
        uncompleted_maze[i] = malloc(sizeof(char) * (maze->x + 1));
        if (uncompleted_maze[i] == NULL)
            return NULL;
        for (int j = 0; j < maze->x; j += 1) {
            uncompleted_maze[i][j] = 'X';
        }
        uncompleted_maze[i][maze->x] = '\0';
    }
    return uncompleted_maze;
}
