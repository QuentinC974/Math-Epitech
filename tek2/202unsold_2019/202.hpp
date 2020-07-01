/*
** EPITECH PROJECT, 2020
** 202unsold_2019
** File description:
** 202
*/

#ifndef UNSOLD_HPP_
#define UNSOLD_HPP_

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>


class unsold
{
private:
    double a;
    double b;
    double JLarray[6][6];
    double Marray[9];
    double Earray[3];
    double Varray[3];
    void joinLawPrint();
    double JLcal(int x, int y);
    void marginalLawPrint();
    void espevarPrint();
    void dashlane();
public:
    void espevar();
    void marginalLaw();
    void joinLaw();
    void print();
    unsold(char **av);
    ~unsold();
};



#endif /* !202_HPP_ */
