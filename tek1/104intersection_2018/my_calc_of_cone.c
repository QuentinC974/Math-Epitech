/*
** EPITECH PROJECT, 2018
** calc my cone
** File description:
** cone calculation
*/

#include "my.h"

void display_my_res(double z_one, double z_two, obj_t line, double d)
{
    printf("Cone with a %.0f degree angle\n", line.r);
    printf("Line passing through the point");
    printf(" (%.0f, %.0f %.0f)", line.xp, line.yp, line.zp);
    printf(" and parallel to the vector");
    printf(" (%.0f, %.0f, %.0f)\n", line.xv, line.yv, line.zv);
    if (d == 0)
        printf("There is an infinite number of intersection points.\n");
    if (z_one == z_two) {
        printf("1 intersection point :\n");
        print_point1(z_one, line);
    } else {
        printf("2 intersection points :\n");
        print_point2(z_one, z_two, line);
    }
}

void display_not_res(obj_t line)
{
    printf("Cone with a %.0f degree angle\nLine passing through the", line.r);
    printf(" point (%.0f, %.0f, %.0f)", line.xp, line.yp, line.zp);
    printf(" and parallel to the vector");
    printf(" (%.0f, %.0f, %.0f)\n", line.xv, line.yv, line.zv);
    printf("No intersection point.\n");
}

void calc_cone(obj_t line)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double z_one = 0;
    double z_two = 0;
    double an = (line.r * M_PI) / 180;
    double teta = pow(tan(an), 2);
    double delta = 0;

    a = pow(line.xv , 2) + pow(line.yv , 2) - (pow(line.zv , 2) * teta);
    b = 2 * line.xp * line.xv + 2 * line.yp * line.yv
        - 2 * line.zp * line.zv * teta;
    c = pow(line.xp , 2) + pow(line.yp , 2) - (pow(line.zp , 2) * teta);
    delta = b * b - 4 * a * c;
    if (delta >= 0) {
        z_one = (-b + sqrt(delta)) / (2 * a);
        z_two = (-b - sqrt(delta)) / (2 * a);
        display_my_res(z_one, z_two, line, delta);
    } else
        display_not_res(line);
}
