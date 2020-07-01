/*
** EPITECH PROJECT, 2019
** titre
** File description:
** moi !
*/

#include "my.h"

double **first(double **values, double **res, double (*bigger)[2])
{
    int i = 1;

    printf("Derivative:\n");
    while (values[i + 1] != NULL) {
        res[i][1] = (values[i + 1][1] - values[i - 1][1]) /
        (values[i + 1][0] - values[i - 1][0]);
        if (res[i][1] > *bigger[1]){
            *bigger[0] = res[i][0];
            *bigger[1] = res[i][1];
        }
        printf("%.1f ml -> %.2f\n", res[i][0], res[i][1]);
        i++;
    }
    printf("\nEquivalent point at %.1f ml\n\n", *bigger[0]);
    return (res);
}

double **second(double **values, double **res)
{
    int i = 2;

    printf("Second derivative:\n");
    while (values[i + 2] != NULL) {
        res[i][1] = (values[i + 1][1] - values[i - 1][1]) /
        (values[i + 1][0] - values[i - 1][0]);
        printf("%.1f ml -> %.2f\n", res[i][0], res[i][1]);
        i++;
    }
    return (res);
}