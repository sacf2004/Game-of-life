/*
** EPITECH PROJECT, 2022
** CPool_08
** File description:
** my_str_to_word_array
*/

#include "my.h"

char **my_arr_dup(char **arr)
{
    int y_max = my_arr_len(arr);
    char **new_arr = malloc(sizeof(char *) * (y_max + 1));

    for (int i = 0; arr[i]; i++)
        new_arr[i] = strdup(arr[i]);
    new_arr[y_max] = NULL;
    return (new_arr);
}
