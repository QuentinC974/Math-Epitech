/*
** EPITECH PROJECT, 2019
** 11°
** File description:
** 11à
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int isnum(char *str);

double calc_to_n(int n, double x)
{
    double res = 1;

    if (x == 0)
        return 1;
    for (int k = 0 ; k <= n ; k++)
        res *= (sin(x / (2 * k + 1))) / (x / (2 * k + 1));
    return (res);
}

double midpoint(int n)
{
    double y = 0;
    double res = 0;

    puts("Midpoint:");
    for (double x = 0.0 ; x < 5000.0 ; x += 0.5)
        y += calc_to_n(n, x + 0.25) * 0.5;
    printf("I%d = %.10f\n", n, y);
    res = fabs(M_PI_2 - y);
    printf("diff = %.10f\n", res);
    return (1);
}

double trapez(int n)
{
    double y1 = 0;
    double y2 = 0;
    double res = 0;

    puts("\nTrapezoidal:");
    for (double x = 0 ; x < 5000 ; x += 0.5) {
        y1 += calc_to_n(n, x);
        y2 += calc_to_n(n, x + 0.5);
    }
    res = (y1 + y2) * 0.25;
    printf("I%d = %.10f\n", n, res);
    res = fabs(M_PI_2 - res);
    printf("diff = %.10f\n", res);
    return (1);
}

double homer(int n, double x, double y1, double y2)
{
    return (0.5 / 6) * (y1 + 4 * calc_to_n(n, x + 0.25) + y2);
}

double simpson(int n)
{
    double res = 0;
    double y1 = 0;
    double y2 = 0;

    puts("\nSimpson:");
    for (double x = 0 ; x < 5000 ; x += 0.5) {
        y1 = calc_to_n(n, x);
        y2 = calc_to_n(n, x + 0.5);
        res += homer(n, x, y1, y2);
    }
    printf("I%d = %.10f\n", n, res);
    res = fabs(M_PI_2 - res);
    printf("diff = %.10f\n", res);
    return (1);
}
