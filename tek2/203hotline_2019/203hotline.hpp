/*
** EPITECH PROJECT, 2020
** 203hotline_2019
** File description:
** 203hotline
*/

#ifndef HOTLINE_HPP_
#define HOTLINE_HPP_

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <chrono>

class hotline
{
private:
    double binomArr[51];
    double poissArr[51];
    double n;
    double k;
    double d;
    double overloadB;
    double overloadP;
    bool iserr(char **av, int nb);
    void pDoub();
    void pSing();
    void binom();
    void poiss();
    void printIt(int64_t Bduration, int64_t Pduration);
    void printb(int64_t Bduration);
    void printp(int64_t Pduration);
public:
    void doub();
    void sing();
    hotline(int ac, char **av);
    ~hotline();
};

void usage();

#endif /* !203HOTLINE_HPP_ */
