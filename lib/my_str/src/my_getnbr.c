/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** function that returns a number, sent to the function as a string
*/

void my_putchar(char c);
int my_getnbr(char const * str);
int my_strlen(char const * str);

int exponancial(int nb)
{
    int temp = 1;
    for (int i = 0; i < nb; i += 1){
        temp *= 10;
    }
    return temp;
}

int build_nb(char const *str, int *start, int *end, int *signe)
{
    long int result = 0;
    for (int i = *start; i <= *end; i += 1){
        result += (str[i] - 48) * exponancial(*end - i);
    }
    if ((*signe % 2) == 1){
        result = - result;
    }
    if ((result < -2147483648) || (result > 2147483647)){
        result = 0;
    }
    int test = result;
    return test;
}

int char_before_int(char const *str)
{
    int start_char = -1;
    int start_int = -1;
    for (int i = 0; i <= (my_strlen(str) + 1); i += 1){
        if ((start_char == -1) && (((str[i] < '0') ||
        (str[i] > '9')) && ((str[i] != '-') && (str[i] != '+')))){
            start_char = i;
        }
        if ((start_int == -1) && (str[i] >= '0') && (str[i] <= '9')){
            start_int = i;
        }
    }
    if (start_char < start_int){
        return 0;
    }
    return 1;
}

int my_getnbr(char const *str)
{
    int start = -1;
    int end = -1;
    int signe = 0;
    int test = char_before_int(str);
    if (test == 0)
        return 0;
    for (int i = 0; i <= (my_strlen(str) + 1); i += 1){
        if ((start == -1) && (str[i] == '-')){
            signe += 1;
        }
        if ((start == -1) && (str[i] >= '0') && (str[i] <= '9')){
            start = i;
        }
        if (((((i > start) && (start != -1)) && (end == -1))
        && (!(str[i] >= '0' && str[i] <= '9')))){
            end = i - 1;
        }
    }
    int result = build_nb(str, &start, &end, &signe);
    return result;
}
