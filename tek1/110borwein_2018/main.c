/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include <stdlib.h>

double calc_to_n(int n, double x);
double midpoint(int n);
double trapez(int n);
double homer(int n, double x, double y1, double y2);
double simpson(int n);
int isnum(char *);

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (isnum(av[1]) == 84)
        return (84);
    midpoint(atoi(av[1]));
    trapez(atoi(av[1]));
    simpson(atoi(av[1]));
}
