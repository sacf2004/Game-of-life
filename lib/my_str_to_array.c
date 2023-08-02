/*
** EPITECH PROJECT, 2022
** CPool_08
** File description:
** my_str_to_word_array
*/

#include "my.h"

int nb_cages (char *str, char sep)
{
    int num = 1;
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (i > 0 && str[i + 1] && (str[i] == sep) && str[i + 1] != sep)
            num++;
    if (str[0] && str[0] == sep && str[1] && str[1] == sep)
        num -= 1;
    return (num);
}

char **my_str_to_array(char *str, char sep)
{
    int num = nb_cages(str, sep);
    char **result = malloc((num + 1) * sizeof(char *));
    int j = 0, z = 0, x = 0, i = 0;

    for (;j < num; x = 0) {
        while (str[x + z] != '\0' && str[x + z] != sep)
            x++;
        if (x == 0 && str[x + z] == sep) {
            z++;
            continue;
        }
        result[j] = malloc(sizeof(char) * (x + 1));
        for (i = 0; i < x; i++, z++)
            result[j][i] = str[z];
        result[j][i] = '\0';
        z++;
        j++;
    }
    result[j] = NULL;
    return (result);
}
