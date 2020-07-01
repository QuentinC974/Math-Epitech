/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>


double calcC(double C, double V);
double calcV(double p, double pSize, double sSize);
void doit();
int error(char **av);
int bridge(char **av);


void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (sujet2, sujet, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "100", "45"};

    int e = bridge(av);
    cr_assert_eq(e, 0, "got %d expected 0", e);
    // cr_assert_stdout_eq_str("Population size:\t\t10000\nSample size:\t\t100\nVoting intentions:\t45.00%\nVariance:\t\t0.002450\n95% confidence interval:\t[35.30%; 54.70%]\n99% confidence interval:\t[32.23%; 57.77%]");
}

Test (fail, s, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "100000", "45"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (fail, s2, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "0", "45"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (fail, s3, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "1", "45"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (fail, p, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "100", "101"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (fail, p2, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "100", "-1"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (failparam, ps, .init=redirect_all_std) {
    char *av[] = {"./209poll", "d", "100", "101"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (failparam, ss, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "e", "101"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (failparam, s, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "100", "d"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (failparam, p, .init=redirect_all_std) {
    char *av[] = {"./209poll", "10000", "100", "p"};

    int e = error(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

Test (calc, C1) {
    double a = calcC(1.96, 0.0024505);
    double b = calcC(2.58, 0.0024505);

    cr_assert_float_eq(a, 0.0970249, 10, "got %d expected 0.0970249", a);
    cr_assert_float_eq(b, 0.127716, 10, "got %d expected 0.127716", b);
}

Test (calc, V1) {
    double b = calcV(0.045, 10000, 100);

    cr_assert_float_eq(b, 0.0024505, 10, "got %d expected 0.0024505", b);
}

Test (failparambridge, s, .init=redirect_all_std) {
    char *av[] = {"./209poll", "e", "100", "45"};
    int e = bridge(av);
    cr_assert_eq(e, 84, "got %d expected 84", e);
}

