/*
** EPITECH PROJECT, 2020
** 205tmo
** File description:
** 205IQ
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

template <class T>
T carre(T a) {return (a * a);}


double func(double x, double u , double s)
{
    double a = (s * sqrt(2.0 * M_PI));
    double b = exp(-1.0 * carre(x - u) / (2 * carre(s)));
    return(b / a);
}

void do3(char **av)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    double u = atoi(av[1]);
    double s = atoi(av[2]);

    for (double i = 0 ; i <= 200 ; i+=1)
        std::cout << (int)i << " " << func(i, u, s) << std::endl;
}

void doO(char **av, double IQ1, double IQ2)
{
    double u = atoi(av[1]);
    double s = atoi(av[2]);
    double res =0;

    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    for (double i = IQ1 ; i <= IQ2 ; i+=0.001)
        res += func(i, u,s);
    if (IQ1 == 0)
        std::cout << round(res) / 10 << "% of people have an IQ inferior to " << (int)IQ2 << std::endl;
    else
        std::cout << round(res) / 10 << "% of people have an IQ between " << (int)IQ1 << " and " << (int)IQ2 << std::endl;
}

void iq(int ac, char **av)
{
    if (ac == 3)
        do3(av);
    else if (ac == 4)
        doO(av, 0, atoi(av[3]));
    else if (ac == 5)
        doO(av, atoi(av[3]), atoi(av[4]));
}

bool error(int ac, char **av)
{
    std::string ustr(av[1]);
    std::string sstr(av[2]);
    if (ustr.find('.') != std::string::npos || sstr.find(".") != std::string::npos) {
        std::cerr << "No decimal number." << std::endl;
        return true;
    }
    if (atoi(ustr.c_str()) < 1 || atoi(ustr.c_str()) > 200)
        return true;
    if (atoi(sstr.c_str()) < 1 || atoi(sstr.c_str()) > 200)
        return true;
    if (ac >= 4) {
        std::string str1(av[3]);
        if (atoi(str1.c_str()) < 1 || atoi(str1.c_str()) > 200)
            return true;
        if (str1.find('.') != std::string::npos) {
            std::cerr << "No decimal number." << std::endl;
            return true;
        }
    }
    if (ac == 5) {
        std::string str1(av[4]);
        std::string str2(av[3]);
        if (str1.find('.') != std::string::npos) {
            std::cerr << "No decimal number." << std::endl;
            return true;
        }
        if (atoi(str1.c_str()) < 1 || atoi(str1.c_str()) > 200)
            return true;
        if (atoi(str1.c_str()) < atoi(str2.c_str()))
            return true;
    }
    return false;
}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./205IQ u s [IQ1] [IQ2]" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tu\tmean" << std::endl;
    std::cout << "\ts\tstandard deviation" << std::endl;
    std::cout << "\tIQ1\tminimum IQ" << std::endl;
    std::cout << "\tIQ2\tmaximum IQ" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac !=3 && ac != 4 && ac != 5) {
        std::cerr << "invalid arguments" << std::endl;
        usage();
        return (84);
    }
    if (error(ac, av)) {
        return 84;
    }
    iq(ac, av);
    return 0;
}