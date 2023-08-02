/*
** EPITECH PROJECT, 2022
** CPool_09
** File description:
** myh
*/

#ifndef MY_H_
    #define MY_H_

    #include <stddef.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>

    int my_str_isnum(char const *str);
    char **my_str_to_array(char *str, char sep);
    int my_arr_len(char **arr);
    char *open_file(char *file);
    void free_arr(char **arr);
    char **my_arr_dup(char **arr);

#endif
