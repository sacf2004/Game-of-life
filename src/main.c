/*
** EPITECH PROJECT, 2023
** solo_stumper_1
** File description:
** main
*/

#include "stumper.h"
#include "my.h"

bool in_map(int x, int y, int max_x, int max_y)
{
    if (x < 0 || y < 0 || x >= max_x || y >= max_y)
        return false;
    return true;
}

int count_neighbors(char **map, int x, int y)
{
    int max_x = strlen(*map), max_y = my_arr_len(map);
    int count = 0;

    if (in_map(x - 1, y - 1, max_x, max_y) && map[y - 1][x - 1] == 'X')
        count = count + 1;
    if (in_map(x, y - 1, max_x, max_y) && map[y - 1][x] == 'X')
        count = count + 1;
    if (in_map(x + 1, y - 1, max_x, max_y) && map[y - 1][x + 1] == 'X')
        count = count + 1;
    if (in_map(x + 1, y, max_x, max_y) && map[y][x + 1] == 'X')
        count = count + 1;
    if (in_map(x + 1, y + 1, max_x, max_y) && map[y + 1][x + 1] == 'X')
        count = count + 1;
    if (in_map(x, y + 1, max_x, max_y) && map[y + 1][x] == 'X')
        count = count + 1;
    if (in_map(x - 1, y + 1, max_x, max_y) && map[y + 1][x - 1] == 'X')
        count = count + 1;
    if (in_map(x - 1, y, max_x, max_y) && map[y][x - 1] == 'X')
        count = count + 1;
    return (count);
}

char check_cell(char **map, int x, int y)
{
    int neighbors = count_neighbors(map, x, y);

    if (map[y][x] == '.' && neighbors == 3)
        return ('X');
    if (map[y][x] == 'X' && neighbors <= 1)
        return ('.');
    if (map[y][x] == 'X' && neighbors >= 4)
        return ('.');
    return (map[y][x]);
}

char **change_map(char **map)
{
    char **new_map = my_arr_dup(map);

    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            new_map[y][x] = check_cell(map, x, y);
        }
    }
    free_arr(map);
    return (new_map);
}

int main(int ac, char **av)
{
    error_handling(ac, av);

    int turns = atoi(av[2]);
    char *file = open_file(av[1]);
    char **map = my_str_to_array(file, '\n');

    free(file);
    while (turns) {
        map = change_map(map);
        turns = turns - 1;
    }

    for (int i = 0; map[i]; i++)
        printf("%s\n", map[i]);
    free_arr(map);
    return (0);
}
