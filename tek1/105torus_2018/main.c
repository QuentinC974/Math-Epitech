/*
** EPITECH PROJECT, 2019
** main funstions
** File description:
** for torus
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double equation(double *ops, double x, int g)
{
    double eq = ops[4] * pow(x, 4) + ops[3] * pow(x, 3) +
                ops[2] * pow(x, 2) + ops[1] * x + ops[0];
    double de = ops[4] * 4 * pow(x, 3) + ops[3] * 3 * pow(x, 2) +
                ops[2] * 2 * x + ops[1];

    if (g == 1)
        return (eq);
    if (g == 2)
        return (de);
    return (eq);
}

int bisection(char **av, double *ops)
{
    double a = 0;
    double b = 1;
    double tmp1 = 0;
    double tmp3 = 0;
    double ans = 0;
    double e = pow(10, ((-1) * atoi(av[7])));
    int i = 1;

    tmp1 = equation(ops, a, 1);
    while (a != b) {
        ans = (a + b) / 2;
        tmp1 = equation(ops, a, 1);
        tmp3 = equation(ops, ans, 1);
        (tmp1 * tmp3 < 0) ? (b = ans) : (a = ans);
        printf("x = %.*f\n", i, ans);
        (i != atoi(av[7])) ? (i++) : (i = i);
        if (fabs(tmp3) < e || fabs(b - a) < e)
            return (1);
    }
    return (0);
}

int newton(char **av, double *ops)
{
    double ans = 1;
    double e = pow(10, ((-1) * atoi(av[7])));
    double tmp1 = equation(ops, ans, 1);
    double tmp2 = 0;
    double tmp3 = 0;
    int i = 1;

    while (42) {
        tmp2 = equation(ops, ans, 2);
        tmp3 = tmp1 / tmp2;
        ans = ans - tmp3;
        tmp1 = equation(ops, ans, 1);
        printf("x = %.*f\n", i, ans);
        i = atoi(av[7]);
        if (fabs(tmp1) < e || fabs(tmp3) < e)
            return (1);
    }
    return (0);
}

int secant(char **av, double *ops)
{
    double ans = 1;
    double e = pow(10, ((-1) * atoi(av[7])));
    double a = 0;
    double b = 1;
    double tmp1 = 0;
    double tmp2 = 0;
    int i = 1;

    while (fabs(equation(ops, ans, 1)) > e) {
        tmp1 = equation(ops, a, 1);
        tmp2 = equation(ops, b, 1);
        ans = (a * tmp2 - b * tmp1) / (tmp2 - tmp1);
        printf("x = %.*f\n", i, ans);
        i = atoi(av[7]);
        a = b;
        b = ans;
    }
    return (0);
}

int main(int ac, char **av)
{
    double ops[5];

    if (ac != 8)
        exit(84);
    ops[0] = atof(av[2]);
    ops[1] = atof(av[3]);
    ops[2] = atof(av[4]);
    ops[3] = atof(av[5]);
    ops[4] = atof(av[6]);
    if (atoi(av[1]) == 1)
        bisection(av, ops);
    if (atoi(av[1]) == 2)
        newton(av, ops);
    if (atoi(av[1]) == 3)
        secant(av, ops);
    return (0);
}
