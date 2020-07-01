/*
** EPITECH PROJECT, 2020
** 204tmp
** File description:
** ducks
*/

#ifndef DUCKS_HPP_
#define DUCKS_HPP_

#include <iostream>
#include <cstring>
#include <cmath>
#include <unistd.h>
#include <iomanip>

class ducks
{
private:
    double a;
    double p2m;
    double p1m;
    double t99;
    double t50;
    double dev;
    double ave;
    double densityFunc(double a, double t);
    double justdoit();
    double calcave();
public:
    ducks(double a);
    ~ducks();
    void printer();
    void doit();

};

#endif /* !DUCKS_HPP_ */
