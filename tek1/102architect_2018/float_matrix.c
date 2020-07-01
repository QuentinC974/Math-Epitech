/*
** EPITECH PROJECT, 2018
** float tab
** File description:
** créer un tableau de float
*/

#include <stdio.h>

void float_matrix(void)
{
    float matrix[3][3] = {0};
    int i = 0;
    int j = 0;

    while (i < 3) {
        while (j < 3) {
            printf ("%.2f\t", matrix[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}
