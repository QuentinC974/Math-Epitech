 /*
** EPITECH PROJECT, 2018
** inits function
** File description:
** for 104 intersection
*/

#include "my.h"

void print_point1(double z1, obj_t line)
{
    double x = line.xv * z1 + line.xp;
    double y = line.yv * z1 + line.yp;
    double z = line.zv * z1 + line.zp;

    printf("(%.3f, %.3f, %.3f)\n", x, y, z);
}

void print_point2(double z1, double z2, obj_t line)
{
    double x = line.xv * z1 + line.xp;
    double y = line.yv * z1 + line.yp;
    double z = line.zv * z1 + line.zp;
    double x3 = line.xv * z2 + line.xp;
    double y3 = line.yv * z2 + line.yp;
    double z3 = line.zv * z2 + line.zp;

    printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    printf("(%.3f, %.3f, %.3f)\n", x3, y3, z3);
}

void check_nb(char **av)
{
    int k = 1;
    
    for (int i = 8 ; i != 0 ; i--) {
        for (int j = 0 ; j < (int)strlen(av[i]) ; j++) {
            k = isdigit(av[i][j]);
            if (k == 0 && av[i][0] != '-') {
                write(2, "bad arguments, retry with -h\n", 29);
                exit(84);
            }
        }
    }   
}

void check_entry(int ac, char **av)
{
    if (ac != 9) {
        write(2, "bad arguments, retry with -h\n", 29);
        exit(84);
    }
    if (atoi(av[1]) < 1 || atoi(av[1]) > 3) {
        write(2, "bad arguments, retry with -h\n", 29);
        exit(84);
    }
}

obj_t init(char **av)
{
    obj_t line;

    line.xp = atof(av[2]);
    line.yp = atof(av[3]);
    line.zp = atof(av[4]);
    line.xv = atof(av[5]);
    line.yv = atof(av[6]);
    line.zv = atof(av[7]);
    line.r = atof(av[8]);
    return (line);
}
