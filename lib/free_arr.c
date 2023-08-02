/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** free_arr
*/

#include "my.h"

void free_arr(char **arr)
{
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
