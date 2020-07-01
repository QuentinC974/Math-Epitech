/*
** EPITECH PROJECT, 2018
** main function
** File description:
** 104intersection
*/

#include "my.h"

int main(int ac, char **av)
{
    obj_t line;

    if (ac == 2 && av[1][1] == 'h' && av[1][0] == '-') {
        usage();
        return (0);
    }
    check_entry(ac, av);
    check_nb(av);
    line = init(av);
    if (atoi(av[1]) == 1) {
        if (atof(av[8]) <= 0)
            exit(84);
        calc_sphere(line);
    }
    if (atoi(av[1]) == 2)
        calc_cyl(line);
    if (atoi(av[1]) == 3)
        calc_cone(line);
    return (0);
}
