/*
** EPITECH PROJECT, 2019
** main
** File description:
** 107
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

char **str_to_tab(char *str, int *row, char sep);
void usage(void);
int isnumber(char *str);

double made_num(char *av, double x)
{
    char **tmp = NULL;
    int row = 0;
    double ret = 0;

    tmp = str_to_tab(av, &row, '*');
    ret = atoi(tmp[0]);
    for (int i = 1 ; i <= row ; i++)
        ret += atoi(tmp[i]) * pow(x, i);
    return (ret);
}

void do_it(int ac, char **av)
{
    double res = 1;

    for (double x = 0 ; x < 1.001 ; x += 0.001) {
        res = 1;
        for (int i = 1 ; i <= ac ; i += 2) {
            if (made_num(av[i + 1], x) == 0)
                exit(84);
            res *= made_num(av[i], x) / made_num(av[i + 1], x);
        }
            printf("%.3f -> %.5f\n", x, res);
        fflush(stdout);
    }
}

int main(int ac, char **av)
{
    ac--;
    if (strcmp(av[1], "-h") == 0)
        usage();
    if (ac % 2 != 0)
        return (84);
    for (int i = 1 ; i < ac + 1 ; i++) {
        if (isnumber(av[i]) == 84)
            return (84);
    }
    do_it(ac, av);
}
