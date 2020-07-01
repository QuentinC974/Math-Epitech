/*
** EPITECH PROJECT, 2018
** cylinder
** File description:
** calculs
*/

#include "my.h"

void disp_cyl(double z1, double z2, double d, obj_t line)
{
    printf("Cylinder of radius %.0f\n", line.r);
    printf("Line passing through the point");
    printf(" (%.0f, %.0f, %.0f)", line.xp, line.yp, line.zp);
    printf(" and parallel to the vector");
    printf(" (%.0f, %.0f, %.0f)\n", line.xv, line.yv, line.zv);
    if (d == 0)
        printf("There is an infinite number of intersection points.\n");
    else if (z1 == z2) {
        printf("1 intersection point :\n");
        print_point1(z1, line);
    } else {
        printf("2 intersection points :\n");
        print_point2(z1, z2, line);
    }
}

void calc_cyl(obj_t line)
{
    double a = pow(line.xv, 2) + pow(line.yv, 2);
    double b = (2 * line.xp * line.xv) + (2 * line.yp * line.yv);
    double c = pow(line.xp, 2) + pow(line.yp, 2) - pow(line.r, 2);
    double d = b * b - 4 * a * c;
    double z1 = 0;
    double z2 = 0;

    if (d >= 0) {
        z1 = (-b + sqrt(d)) / (2 * a);
        z2 = (-b - sqrt(d)) / (2 * a);
        disp_cyl(z1, z2, d, line);
    } else {
        printf("Cylinder of radius %.0f\n", line.r);
        printf("Line passing through the point");
        printf(" (%.0f, %.0f, %.0f)", line.xp, line.yp, line.zp);
        printf(" and parallel to the vector");
        printf(" (%.0f, %.0f, %.0f)\n", line.xv, line.yv, line. zv);
        printf("No intersection point.\n");
    }
}
