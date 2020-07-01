/*
** EPITECH PROJECT, 2019
** test
** File description:
** 110 
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

double calc_to_n(int n, double x);
double midpoint(int n);
double trapez(int n);
double homer(int n, double x, double y1, double y2);
double simpson(int n);
int isnum(char *);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (midpoint, 4, .init=redirect_all_std) {
    midpoint(4);
    fflush(stdout);
    cr_assert_stdout_eq_str("Midpoint:\nI4 = 1.5707963268\ndiff = 0.0000000000\n");
}

Test (midpoint, 9, .init=redirect_all_std) {
    midpoint(9);
    fflush(stdout);
    cr_assert_stdout_eq_str("Midpoint:\nI9 = 1.5707961801\ndiff = 0.0000001467\n");
}

Test (trapez, 4, .init=redirect_all_std) {
    trapez(4);
    fflush(stdout);
    cr_assert_stdout_eq_str("\nTrapezoidal:\nI4 = 1.5707963268\ndiff = 0.0000000000\n");
}

Test (trapez, 9, .init=redirect_all_std) {
    trapez(9);
    fflush(stdout);
    cr_assert_stdout_eq_str("\nTrapezoidal:\nI9 = 1.5707961801\ndiff = 0.0000001467\n");
}

Test (sims, 4, .init=redirect_all_std) {
    simpson(4);
    fflush(stdout);
    cr_assert_stdout_eq_str("\nSimpson:\nI4 = 1.5707963268\ndiff = 0.0000000000\n");
}

Test (sims, 9, .init=redirect_all_std) {
    simpson(9);
    fflush(stdout);
    cr_assert_stdout_eq_str("\nSimpson:\nI9 = 1.5707961801\ndiff = 0.0000001467\n");
}

Test (calc_n, x0) {
    cr_assert_eq(calc_to_n(9, 0), 1);
}

Test (isnum, 0) {
    cr_assert_eq(isnum("0"), 0);
}

Test (isnum, a) {
    cr_assert_eq(isnum("a"), 84);
}

Test (isnum, bakc) {
    cr_assert_eq(isnum("\0"), 84);
}
