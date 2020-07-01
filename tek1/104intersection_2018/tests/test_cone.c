/*
** EPITECH PROJECT, 2018
** tests
** File description:
** unit tests to err
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(failed_cone, out, .init = redirect_all_std)
{
    obj_t line;
    char *av[] = {"./104intersection", "3","34", "5", "2", "5", "6", "7", "8"};

    line = init(av);
    calc_cone(line);
    fflush(NULL);
    cr_assert_stdout_eq_str("Cone whit a 8 degree angle\nLine passing through \
the point (34, 5, 2) \
and parallel to the vector (5, 6, 7)\nNo intersection point.\n");
}

Test(failed_Cylinder, output, .init = redirect_all_std)
{
    obj_t line;
    char *av[] = {"./104intersection", "2","34", "5", "2", "5", "6", "7", "8"};

    line = init(av);
    calc_cyl(line);
    fflush(NULL);
    cr_assert_stdout_eq_str("Cylinder of radius 8\nLine passing through \
the point (34, 5, 2) \
and parallel to the vector (5, 6, 7)\nNo intersection point.\n");
}

Test(failed_Sphere, output, .init = redirect_all_std)
{
    obj_t line;
    char *av[] = {"./104intersection", "1","34", "5", "2", "5", "6", "7", "8"};

    line = init(av);
    calc_sphere(line);
    fflush(NULL);
    cr_assert_stdout_eq_str("Sphere of radius 8\nLine passing \
through the point (34, 5, 2) \
and parallel to the vector (5, 6, 7)\nNo intersection point.\n");
}
