/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

char **str_to_tab(char *str, char sep);
void usage(void);
int isnum(char *str);
int do_it(char *);
int test_it(char **values, int e);
int count_it(char *filepath);
int check_file(char *filepath);
int check_error(char **av);
double **first(double **values, double **res, double (*bigger)[2]);
double **second(double **values, double **res);
double **third(double **values, double *equi);
char **create(char *filepath);
double **init_tab(char **val);

#endif
