/*
** EPITECH PROJECT, 2019
** 106
** File description:
** Bo0m Bix
*/

#include "my.h"

void task1(char **av)
{
    double n = atoi(av[1]);
    double k = atof(av[2]);

    printf("1 %.2f\n", n);
    fflush(stdout);
    for (int i = 1 ; i < 100 ; i++) {
        n = k * n * (1000 - n) / 1000;
        printf("%d %.2f\n", i + 1, n);
        fflush(stdout);
    }
}

void task2(char **av)
{
    int start = atoi(av[2]);
    int end = atoi(av[3]);
    double n = atof(av[1]);

    for (double e = 1 ; e <= 4 ; e += 0.01) {
        n = atof(av[1]);
        for (double i = 1 ; i < end ; i++) {
            n = (e * n * (1000 - n) / 1000);
            if (i >= start - 1) {
                printf("%.2f %.2f\n", e, n);
                fflush(stdout);
            }
        }
    }
}
