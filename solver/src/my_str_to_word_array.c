/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-bsantman-antoine.filleul
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
char *my_strndup(char const *src, int n, int y, char key);

int is_good(char c, char key)
{
    if (c == key || c == '\0') {
        return 1;
    }
    if (c != key && c != '\0' && c != '*' && c != 'X')
        exit(84);
    return 0;
}

int count_words(char const *str, char key)
{
    int count = 0;
    for (int i = 0; str[i] != '\0';i++) {
        if (is_good(str[i], key) == 1 && is_good(str[i + 1], key) == 0) {
                count += 1;
        }
    }
    return (count + 1);
}

int shittyloop(char const *str, int y, char key)
{
    while (is_good(str[y], key) == 0) {
            ++y;
    }
    return y;
}

char **function(char const *str, int nbw, char **array, char key)
{
    int i = 0;
    int z = 0;
    int y = 0;
    while (z != nbw && str[i] != '\0') {
        if (is_good(str[i], key) == 0) {
            y = i;
            y = shittyloop(str, y, key);
            array[z] = my_strndup(str, y - i, i, key);
            i = y;
            z++;
        }
        if (array[z - 1] == NULL)
            return NULL;
        i++;
    }
    return array;
}

char **my_str_to_word_array(char const *str, char key)
{
    int nbw = count_words(str, key);
    char **array = malloc(sizeof(char*) * (nbw +1));
    if (array == NULL)
        return NULL;
    array[nbw] = NULL;
    function(str, nbw, array, key);
    if (array[0][0] != '*') return NULL;
    return array;
}
