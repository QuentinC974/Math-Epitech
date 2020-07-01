/*
** EPITECH PROJECT, 2019
** this
** File description:
** is math
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (strcmp(av[1], "-h") == 0)
        usage();
    return (check_error(av) == -1 ? 84 : do_it(av[1]));
}
