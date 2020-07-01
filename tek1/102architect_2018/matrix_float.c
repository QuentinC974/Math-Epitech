/*
** EPITECH PROJECT, 2018
** float tab
** File description:
** créer un tableau de float
*/

#include <stdio.h>
#include "my.h"
#include "struct.h"
#include "math.h"

matrix_t calc_translation(int nb1, int nb2, matrix_t mat)
{
    mat.res1 = mat.res1 + nb1;
    mat.res2 = mat.res2 + nb2;
    mat.matrix[0][2] = mat.matrix[0][2] + nb1;
    mat.matrix[1][2] = mat.matrix[1][2] + nb2;
    return (mat);
}

matrix_t calc_scale(int nb1, int nb2, matrix_t mat)
{
    mat.res1 *= nb1;
    mat.res2 *= nb2;
    mat.matrix[0][0] *= nb1;
    mat.matrix[1][1] *= nb2;
    return (mat);
}

matrix_t calc_rotate(int nb, matrix_t mat)
{
    mat.matrix[0][0] *= (cos(nb * M_PI / 180) * 180/M_PI);
    mat.matrix[0][1] *= (sin(nb * M_PI / 180) * 180/M_PI);
    mat.matrix[1][0] *= (-sin(nb * M_PI / 180 * 180/M_PI));
    mat.matrix[1][1] *= (cos(nb * M_PI / 180 * 180/M_PI));
    return (mat);
}
