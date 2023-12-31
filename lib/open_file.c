/*
** EPITECH PROJECT, 2022
** bs_myls
** File description:
** open_file
*/

#include "my.h"

char *open_file(char *path)
{
    struct stat st;
    stat (path, &st);
    int fd = open (path, O_RDONLY);
    int sz = st.st_size;
    char *buff = NULL;
    int rd = 0;

    if (fd == -1)
        return (NULL);
    buff = malloc(sz + 1);
    rd = read (fd, buff, sz);
    if (rd == -1) {
        free(buff);
        return (NULL);
    }
    buff[sz] = '\0';
    close (fd);
    return (buff);
}
