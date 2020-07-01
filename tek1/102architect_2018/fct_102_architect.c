/*
** EPITECH PROJECT, 2018
** 102 architect
** File description:
** Projet Mathematique
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my.h"

int check_error(int x)
{
    if (x == 0)
        return (0);
    usage();
    return (42);
}

matrix_t fct_102_architect(char **av, matrix_t mat)
{
    int count = 0;

    while (av[count] != NULL) {
        if (strcmp(av[count], "-t") == 0)
            mat = translation(av[count + 1], av[count + 2], mat);
        if (strcmp(av[count], "-z") == 0)
            mat = scaling(av[count + 1], av[count + 2], mat);
        if (strcmp(av[count], "-r") == 0)
            mat = rotation(av[count + 1], mat);
        if (strcmp(av[count], "-s") == 0)
            mat = reflection(av[count + 1], mat);
        count++;
        mat.x = check_error(mat.x);
    }
    return (mat);
}
