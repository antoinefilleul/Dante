/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** function that copies a string into another
*/

int my_strlen (char const * str);

char * my_strcpy (char *dest, char const *src)
{
    int len = my_strlen(src);
    for (int i = 0; i <= len + 1; i += 1){
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}
