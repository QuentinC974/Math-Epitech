/*
** EPITECH PROJECT, 2019
** titre
** File description:
** moi !
*/

#include "my.h"

double **init_third(double **values, double *equi)
{
    int i = 0;
    double j = 0;
    int k = 0;
    double **res3 = NULL;
    double delta = 0;
    double val = 0;
    int a = 0;

    for (; values[i][0] != equi[0] ; i++);
    for (j = values[i - 1][0] ; (int)(j* 10) != (int)(values[i + 1][0] *10)
        ; j += 0.1, k++);
    res3 = malloc(sizeof(double *) * k);
    delta = (values[i - 1][1] - values[i][1]) /
            ((values[i - 1][0] - values[i][0]) * 10);
    val = values[i - 1][1];
    j = values[i - 1][0];
    for (int f = 0 ; f < k ; f++, j += 0.1, val += delta) {
        res3[f] = malloc(sizeof(double) * 3);
        res3[f][0] = j;
        if ((int)(res3[f][0] * 10) == (int)(equi[0] * 10) && a == 0) {
            delta = (values[i][1] - values[i + 1][1]) /
                    ((values[i][0] - values[i + 1][0]) * 10);
            val = values[i][1];
            f--;
            j -= 0.1;
            a = 1;
        }
        res3[f][1] = val;
    }
    res3[k] = NULL;
    return (res3);
}

double **third(double **values, double *equi)
{
    int i = 1;
    double **res = init_third(values, equi);
    double bigger = 0;

    printf("\nSecond derivative estimated:\n");
    printf("%.1f ml -> %.2f\n", res[0][0], res[0][1]);
    while (res[i + 1] != NULL) {
        if (res[i][1] < 0 && res[i - 1][1] > 0)
            bigger = res[i - 1][0];
        printf("%.1f ml -> %.2f\n", res[i][0], res[i][1]);
        i++;
    }
    printf("%.1f ml -> %.2f\n", res[i][0], res[i][1]);

    printf("\nEquivalent point at %.1f ml\n", bigger);
    return (res);
}