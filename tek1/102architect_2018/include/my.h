/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include "struct.h"

void my_putchar(char c);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_isneg(int nb);

int my_put_nbr(int nb);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_commute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

void my_swap(int *a, int *b);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strdup(char const *src);

char *clean(char *str);

int compar(char *nb1, char *nb2);

int add(int a, int b);

int sub(int a, int b);

int mul(int a, int b);

int my_div(int a, int b);

int mod(int a, int b);

int fonc(char **av);

char *infin_add(char *num1, char *num2);

char *infin_sub(char *num1, char *num2);

char *infi_mul(char *num1, char *num2);

char *infin_div(char *num1, char *num2);

char *infin_mod(char *num1, char *num2);

char **add_infin_mul(char **tab, int *count);

char **shunting(char *str_regle, char *str_r_n, char *str, int size);

void my_putnbr_base(int nb, char const *base);

void my_putunsigned_nbr(unsigned int nb);

int my_printf(char *str, ...);

int usage(void);

matrix_t translation(char *param1, char *param2, matrix_t mat);

matrix_t scaling(char *param1, char *param2, matrix_t mat);

matrix_t rotation(char *param, matrix_t mat);

matrix_t reflection(char *param, matrix_t mat);

matrix_t fct_102_architect(char **array, matrix_t mat);

matrix_t float_matrix(matrix_t mat);

matrix_t calc_scale(int nb1, int nb2, matrix_t mat);

matrix_t calc_translation(int nb1, int nb2, matrix_t mat);

matrix_t calc_rotate(int nb, matrix_t mat);

matrix_t init_struct(int x, int y, matrix_t mat);

void print_result(matrix_t mat, int x, int y);

#endif
