/*
** EPITECH PROJECT, 2023
** solo_stumper_1
** File description:
** main
*/

#include "stumper.h"
#include "my.h"

bool valid_map(char *file)
{
    for (int i = 0; file[i]; i++) {
        if (file[i] != '.' && file[i] != 'X' && file[i] != '\n')
            return false;
    }

    char **map = my_str_to_array(file, '\n');
    int len = strlen(*map);

    for (int i = 0; map[i]; i++) {
        if (len != strlen(map[i])) {
            free_arr(map);
            return false;
        }
    }
    free_arr(map);
    return true;
}

void error_handling(int ac, char **av)
{
    char *file = NULL;

    if (ac != 3)
        exit(84);
    file = open_file(av[1]);
    if (!file)
        exit(84);
    if (!valid_map(file)) {
        free(file);
        exit(84);
    }
    free(file);
    if (!my_str_isnum(av[2]))
        exit(84);
}
