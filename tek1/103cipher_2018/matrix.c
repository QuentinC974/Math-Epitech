/*
** EPITECH PROJECT, 2018
** matrix
** File description:
** function
*/

#include "my.h"

int **claim(int **matrix, int *convert, mat_size_t *size, int len)
{
    int cpt = 0;
    int cpt2 = 0;
    int x = 0;

    while (cpt != size->row) {
        cpt2 = 0;
        while (cpt2 != size->col) {
            if (x < len)
                matrix[cpt][cpt2] = convert[x];
            else
                matrix[cpt][cpt2] = 0;
            cpt2++;
            x++;
        }
        cpt++;
    }
    return (matrix);
}

int **do_key_matrix(int *convert, int x, int *cpt, mat_size_t *mat_size)
{
    int cpt2 = 0;
    int cpt3 = 1;
    int **matrix;

    while (x > pow(cpt3, 2))
        cpt3 += 1;
    matrix = malloc(sizeof(int *) * cpt3);
    while (cpt2 != cpt3) {
        matrix[cpt2] = malloc(sizeof(int) * cpt3);
        cpt2++;
    }
    mat_size->row = cpt3;
    mat_size->col = cpt3;
    matrix = claim(matrix, convert, mat_size, x);
    *cpt = cpt3;
    return (matrix);
}

int **do_msg_matrix(int *convert, int x, int cpt, mat_size_t *mat_size)
{
    int cpt2 = 0;
    int cpt3 = 1;
    int **matrix;
    float how = (float)x /(float)cpt;

    while (cpt3 < how)
        cpt3++;
    matrix = malloc(sizeof(int *) * cpt3);
    while (cpt2 != cpt3) {
        matrix[cpt2] = malloc(sizeof(int) * cpt);
        cpt2++;
    }
    mat_size->row = cpt3;
    mat_size->col = cpt;
    matrix = claim(matrix, convert, mat_size, x);
    return (matrix);
}

int **key_matrix(char *bkey, int *nb_col, mat_size_t *size)
{
    int x = strlen(bkey);
    int cpt = 0;
    int *convert = malloc(sizeof(int) * x);;
    int **key;

    while (cpt != x) {
        convert[cpt] = bkey[cpt];
        cpt += 1;
    }
    key = do_key_matrix(convert, x, nb_col, size);
    print_key(key, *size);
    return (key);
}

int **msg_matrix(char *bmsg, int nb_col, mat_size_t *size)
{
    int x = strlen(bmsg);
    int cpt = 0;
    int *convert = malloc(sizeof(int) * x);;
    int **msg;

    while (cpt != x) {
        convert[cpt] = bmsg[cpt];
        cpt++;
    }
    msg = do_msg_matrix(convert, x, nb_col, size);
    return (msg);
}
