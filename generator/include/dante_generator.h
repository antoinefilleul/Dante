/*
** EPITECH PROJECT, 2023
** B-CPE-200-BDX-2-1-dante-killian.trouve
** File description:
** dante
*/

#include "maze.h"
#include "directions.h"

#ifndef DAN_TE
    #define DAN_TE
    #define OK 0;
    #define KO 84;
    void generate_perfect_maze(char **uncompleted_maze,
    int **all_directions, int x, int y);
    int print_maze(maze_t *maze, char **completed_maze);
    void random_directions(int **all_directions);
    int setup_direction(int **all_directions);
    char **fill_maze_with_walls(maze_t *maze);
    int imperfect_setup(maze_t *maze, int x, int y);

#endif /* !DAN_TE */
