/*
** EPITECH PROJECT, 2019
** this is
** File description:
** err.c
*/

#include "my.h"

int test_it(char **value, int e)
{
    int c = 0;
    char **tmp = NULL;

    while (c != e) {
        tmp = str_to_tab(value[c], ';');
        if (isnum(tmp[0]) == -1 || strlen(tmp[0]) == 0)
            return (-1);
        if (isnum(tmp[1]) == -1 || strlen(tmp[1]) == 0)
            return (-1);
        c++;
    }
    return (1);
}

int count_it(char *filepath)
{
    FILE *fd = fopen(filepath, "r");
    size_t s = 0;
    int i = 0;
    char *tmp = NULL;

    if (fd == NULL)
        return (-1);
    while (getline(&tmp, &s, fd) != -1)
        i++;
    fclose(fd);
    return (i);
}

int check_file(char *filepath)
{
    int	i = count_it(filepath);
    FILE *fd = fopen(filepath, "r");
    size_t s = 0;
    char **values = malloc(sizeof(char *) * (i + 1));
    int e = 0;

    for (int u = 0 ; u != i ; u++)
        values[u] = NULL;
    while (getline(&values[e], &s, fd) != -1)
        e++;
    values[e] = NULL;
    fclose(fd);
    if (e < 3)
        return (-1);
    return (test_it(values, e));
}

int check_error(char **av)
{
    return (check_file(av[1]));
}
