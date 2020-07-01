/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include "unistd.h"

int errno(int ac, char **av)
{
    int z = isnumber(av[1]);
    int y = isnumber(av[2]);
    int x = 0;

    if (ac == 4)
        x = isnumber(av[3]);
    if (x == 84 || y == 84 || z == 84)
        return (84);
    if (ac == 3 && (atof(av[1]) < 0 || atof(av[2]) < 0))
        return (84);
    if (ac == 3 && (atof(av[1]) < 0 || atof(av[2]) < 0))
        return (84);
    if (ac == 4 && (atof(av[3]) < 0))
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][1] == 'h' && av[1][0] == '-' && av[1][2] == 0) {
        usage();
        return (0);
    }
    if ((ac != 3 && ac != 4) || errno(ac, av) == 84)
        return (84);
    if (ac == 3) {
        if (atof(av[2]) < 0 || atof(av[2]) > 4)
            return (84);
        task1(av);
    } else if (ac == 4) {
        if (atof(av[2]) < 0 || atof(av[3]) < 0)
            return (84);
        task2(av);
    } else {
        write(2, "Bad argument !\n", 16);
        return (84);
    }
    return (0);
}
