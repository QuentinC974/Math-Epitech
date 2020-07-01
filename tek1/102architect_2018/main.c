/*
** EPITECH PROJECT, 2018
** main
** File description:
** main fonction
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"

int main(int ac, char **av)
{
    matrix_t mat;

    if (ac == 2 && strcmp(av[1], "-h") == 0)
        usage();
    mat = init_struct(atoi(av[1]), atoi(av[2]), mat);
    if (ac >= 5) {
        mat = fct_102_architect(av, mat);
        if (mat.x == 42) {
            return (84);
        }
    } else
        return (84);
    print_result(mat, atoi(av[1]), atoi(av[2]));
    return (0);
}
