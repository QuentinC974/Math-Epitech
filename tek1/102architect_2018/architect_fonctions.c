/*
** EPITECH PROJECT, 2018
** architect fonctions
** File description:
** all fonctions
*/

#include <stdio.h>
#include "my.h"
#include "ctype.h"

int check_if_nbr(char *str)
{
    int res = 0;
    int cpt = 0;

    if (str[cpt] == '-')
        cpt++;
    while (str[cpt] != '\0') {
        res = isdigit(str[cpt]);
        if (res == 0)
            return (42);
        cpt++;
    }
    return (0);
}

matrix_t translation(char *param1, char *param2, matrix_t mat)
{
    int res = 0;
    int res2 = 0;
    int nbr1 = 0;
    int nbr2 = 0;

    if (param1 == NULL || param2 == NULL) {
        mat.x = 42;
        return (mat);
    }
    nbr1 = my_getnbr(param1);
    nbr2 = my_getnbr(param2);
    res = check_if_nbr(param1);
    res2 = check_if_nbr(param2);
    if (res == 42 || res2 == 42) {
        mat.x = 42;
        return (mat);
    }
    printf("Translation along vector (%d, %d)\n", nbr1, nbr2);
    mat = calc_translation(nbr1, nbr2, mat);
    return (mat);
}

matrix_t scaling(char *param1, char *param2, matrix_t mat)
{
    int res = 0;
    int res2 = 0;
    int nbr1 = 0;
    int nbr2 = 0;

    if (param1 == NULL || param2 == NULL) {
        mat.x = 42;
        return (mat);
    }
    nbr1 = my_getnbr(param1);
    nbr2 = my_getnbr(param2);
    res = check_if_nbr(param1);
    res2 = check_if_nbr(param2);
    if (res == 42 || res2 == 42) {
        mat.x = 42;
        return (mat);
    }
    mat = calc_scale(nbr1, nbr2, mat);
    printf("Scaling by factors %d and %d\n", nbr1, nbr2);
    return (mat);
}

matrix_t rotation(char *param, matrix_t mat)
{
    int res = 0;
    int nbr = 0;

    (void)mat;
    if (param == NULL) {
        mat.x = 42;
        return (mat);
    }
    nbr = my_getnbr(param);
    res = check_if_nbr(param);
    if (res == 42) {
        mat.x = 42;
        return (mat);
    }
    mat = calc_rotate(nbr, mat);
    printf("Rotation by a %d degree angle\n", nbr);
    return (mat);
}

matrix_t reflection(char *param, matrix_t mat)
{
    int res = 0;
    int nbr = 0;

    (void)mat;
    if (param == NULL) {
        mat.x = 42;
        return (mat);
    }
    nbr = my_getnbr(param);
    res = check_if_nbr(param);
    if (res == 42) {
        mat.x = 42;
        return (mat);
    }
    printf("%s", "Reflection over and axis with an inclination angle");
    printf("of %d degrees\n", nbr);
    return (mat);
}
