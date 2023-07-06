/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-remi.mazat
** File description:
** my_strndup
*/

#include <stdlib.h>
int is_good(char c, char key);

char *my_strndup(char const *src, int n, int y, char key)
{
    if (src == NULL)
        return NULL;
    int i = 0;
    char *str;
    str = malloc(sizeof(char) * (n + 1));
    if (str == NULL)
        return NULL;
    while (i < n) {
        if (is_good(src[y], key) == 1) {
            y = y + 1;
        }
        str[i] = src[y];
        y = y + 1;
        i = i + 1;
    }
    str[n] = '\0';
    return str;
}
