/*
** EPITECH PROJECT, 2018
** calculs to execute
** File description:
** for cipher
*/

#include "my.h"

int **malloc_mat(mat_size_t size)
{
    int **crypt_msg;
    int cpt = 0;
    int cpt2 = 0;

    crypt_msg = malloc(sizeof(int *) * size.row);
    while (cpt2 != size.row) {
        crypt_msg[cpt2] = malloc(sizeof(int) * size.col);
        cpt2++;
    }
    while (cpt != size.row) {
        cpt2 = 0;
        while (cpt2 != size.col) {
            crypt_msg[cpt][cpt2] = 0;
            cpt2++;
        }
        cpt++;
    }
    return (crypt_msg);
}

int **mul_matrix(int **key, mat_size_t key_s, int **msg, mat_size_t msg_s)
{
    int **crypt_msg = malloc_mat(msg_s);

    for (int nb = 0 ; nb != msg_s.row ; nb++) {
        for (int cpt = 0 ; cpt != key_s.row ; cpt++) {
            for (int cpt2 = 0 ; cpt2 != msg_s.col ; cpt2++)
                crypt_msg[nb][cpt] += msg[nb][cpt2] * key[cpt2][cpt];
        }
    }
    print_msg(crypt_msg, msg_s);
    return (crypt_msg);
}
