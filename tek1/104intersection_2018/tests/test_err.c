/*
** EPITECH PROJECT, 2018
** err arg
** File description:
** unit test to arg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_stde(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(less_arg, out, .init = redirect_all_stde, .exit_code = 84)
{
    char *av[] = {"i", "3","34", "5", "2", "5", "6", "7"};

    check_entry(8, av);
    fflush(NULL);
    cr_assert_stderr_eq_str("bad arguments, retry with -h\n");
}

Test(err_first, out, .init = redirect_all_stde, .exit_code = 84)
{
    char *av[] = {"i", "4","34", "5", "2", "5", "6", "7", "9"};

    check_entry(9, av);
    fflush(NULL);
    cr_assert_stderr_eq_str("bad arguments, retry with -h\n");
}
