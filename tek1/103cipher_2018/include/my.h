/*
** EPITECH PROJECT, 2018
** my functions
** File description:
** look te title
*/

#ifndef __MY_H__
#define __MY_H__

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct mat_size
{
    int row;
    int col;
} mat_size_t;

int **mul_matrix(int **key, mat_size_t key_s, int **msg, mat_size_t msg_s);
int **claim(int **matrix, int *convert, mat_size_t *size, int len);
int **do_key_matrix(int *convert, int x, int *cpt, mat_size_t *mat_size);
int **do_msg_matrix(int *convert, int x, int cpt, mat_size_t *mat_size);
int **key_matrix(char *bkey, int *nb_col, mat_size_t *size);
int **msg_matrix(char *bmsg, int nb_col, mat_size_t *size);
int **malloc_mat(mat_size_t size);
void print_key(int **key, mat_size_t key_s);
void print_msg(int **msg, mat_size_t msg_s);
void usage(void);

#endif
