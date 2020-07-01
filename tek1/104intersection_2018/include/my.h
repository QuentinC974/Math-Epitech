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
#include <unistd.h>
#include <ctype.h>

typedef struct obj
{
    float xp;
    float yp;
    float zp;
    float xv;
    float yv;
    float zv;
    float r;
} obj_t;

void check_nb(char **av);
void check_entry(int ac, char **av);
obj_t init(char **av);
void print_point1(double z1, obj_t line);
void print_point2(double z1, double z2, obj_t line);
void calc_cone(obj_t line);
void calc_sphere(obj_t line);
void calc_cyl(obj_t line);
void calc_cone(obj_t line);
void calc_sphere(obj_t line);
void usage(void);

#endif
