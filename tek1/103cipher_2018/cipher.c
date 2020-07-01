/*
** EPITECH PROJECT, 2018
** cipher
** File description:
** math project
*/

#include "my.h"

void print_key(int **key, mat_size_t key_s)
{
    int cpt = 0;
    int cpt2 = 0;

    printf("Key matrix :\n");
    while (cpt != key_s.row) {
        while (cpt2 != key_s.col) {
            printf("%i",key[cpt][cpt2]);
            if (cpt2 < key_s.col - 1)
                printf("\t");
            cpt2++;
        }
        printf("\n");
        cpt2 = 0;
        cpt++;
    }
    printf("\n");
}

void print_msg(int **msg, mat_size_t msg_s)
{
    int cpt = 0;
    int cpt2 = 0;

    printf("Encrypted message :\n");
    printf("%i", msg[cpt][cpt2]);
    cpt2++;
    while (cpt != msg_s.row) {
        while (cpt2 != msg_s.col) {
            printf(" %i", msg[cpt][cpt2]);
            cpt2++;
        }
        cpt2 = 0;
        cpt++;
    }
    printf("\n");
}

void do_it(char **av)
{
    int **key;
    int **msg;
    int nb_col = 1;
    mat_size_t key_s;
    mat_size_t msg_s;
    int to_do = 2;

    to_do = atoi(av[3]);
    if (to_do == 0) {
        key = key_matrix(av[2], &nb_col, &key_s);
        msg = msg_matrix(av[1], nb_col, &msg_s);
        mul_matrix(key, key_s, msg, msg_s);
    }
    else if (to_do == 1)
        printf("not support\n");
    else
        printf("please use 0 to encrypt or 1 to decrypt\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-'&& av[1][1] == 'h' && av[1][2] == '\0') {
        usage();
        return (0);
    }
    if (ac != 4)
        exit(84);
    do_it(av);
    return (0);
}
