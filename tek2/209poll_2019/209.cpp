/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** 209
*/

#include "209.hpp"

double calcC(double C, double V)
{
    double c =  C * sqrt(_v);
    return c < 0 ? 0 : c > 1 ? 1 : c;
}

double calcV(double p, double pSize, double sSize)
{
    double a = ((p * (1.0 - p)) / sSize);
    double b = ((pSize - sSize)/(pSize - 1.0));
    double v =  a*b ;
    return v;
}

void doit()
{
    _v = calcV(_p, _pSize, _sSize);
    double c95 = calcC(1.96, _v);
    double c99 = calcC(2.58, _v);

    std::cout << std::fixed;
    std::cout << std::setprecision(0);

    std::cout << "Population size:\t" << _pSize << std::endl;
    std::cout << "Sample size:\t\t" << _sSize << std::endl;
    std::cout << std::setprecision(2);
    std::cout << "Voting intentions:\t" << _p * 100 << "%" << std::endl;
    std::cout << std::setprecision(6);
    std::cout << "Variance:\t\t" << _v << std::endl;
    std::cout << std::setprecision(2);
    std::cout << "95% confidence interval:\t[" << (_p - c95) * 100 << "%; "
              << (_p + c95) * 100 << "%]" << std::endl;
    std::cout << "99% confidence interval:\t[" << (_p - c99) * 100 << "%; "
              << (_p + c99) * 100 << "%]" << std::endl;
}

int  error(char **av)
{
    try {
        _pSize = std::stol(av[1]);
    } catch (std::exception const &e) {
            std::cerr << "pSize is not a valid number";
            return (84);
    }
    try {
        _sSize = std::stol(av[2]);
    } catch (std::exception const &e) {
            std::cerr << "sSize is not a valid number";
            return (84);
    }
    try {
        _p = std::stof(av[3]);
    } catch (std::exception const &e) {
            std::cerr << "p is not a valid number";
            return (84);
    }
    if (_sSize > _pSize) {
        std::cerr << "Sample is greater than the population" << std::endl;
        return (84);
    }
    if (_p > 100.0) {
        std::cerr << "Percentage is greater than 100%" << std::endl;
        return (84);
    }
    if (_p < 0.0) {
        std::cerr << "Percentage must be positive" << std::endl;
        return (84);
    }
    if (_sSize <= 1) {
        std::cerr << "There is not enough population sampled" << std::endl;
        return (84);
    }
    _p /= 100;
}

int bridge(char **av)
{
    if (error(av) == 84)
        return (84);
    doit();
    return 0;
}