/*
** EPITECH PROJECT, 2018
** init
** File description:
** and result;
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"
#include "struct.h"


void print_result(matrix_t mat, int x, int y)
{
    int cpt = 0;

    while (cpt != 3) {
            printf("%.2f", mat.matrix[cpt][0]);
            printf("   %.2f", mat.matrix[cpt][1]);
            printf("   %.2f\n", mat.matrix[cpt][2]);
            cpt++;
    }
    printf("(%i, %i) =>", x, y);
    printf(" (%.2f, %.2f)\n", mat.res1, mat.res2);
}

matrix_t init_struct(int x, int y, matrix_t mat)
{
    mat.res1 = x;
    mat.res2 = y;
    mat.matrix[0][0] = 1.00;
    mat.matrix[0][1] = 0.00;
    mat.matrix[0][2] = 0.00;
    mat.matrix[1][0] = 0.00;
    mat.matrix[1][1] = 1.00;
    mat.matrix[1][2] = 0.00;
    mat.matrix[2][0] = 0.00;
    mat.matrix[2][1] = 0.00;
    mat.matrix[2][2] = 1.00;
    return (mat);
}
