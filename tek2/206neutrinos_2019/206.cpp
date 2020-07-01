/*
** EPITECH PROJECT, 2020
** 206neutrinos_2019
** File description:
** 206
*/

#include "206.hpp"

template <class T>
T car(T a) {return (a * a);}

void n206::c_dev(double nv)
{
    double a = ((_ari * (_nbV - 1)) + nv) / _nbV;
    double b = (car(_dev) + car(_ari)) *  (_nbV - 1);

    _dev =  sqrt(((b + car(nv)) / _nbV) - car(a));
}

void n206::newval()
{
    _nbV = _nbV + 1;
}

void n206::c_ari(double nv)
{
    if (_nbV == 0.0) {
        std::cerr << "c_ari err: div by 0" << std::endl;
        exit(84);
    }
    _ari = _ari + (nv - _ari) / _nbV;
}

void n206::c_roo(double nv)
{
    if (_nbV == 0.0) {
        std::cerr << "c_roo err: div by 0" << std::endl;
        exit(84);
    }
    _roo =  sqrt(car(_dev) + car(_ari));
}

void n206::c_har(double nv)
{ 
    if (_nbV == 0.0 || _ari == 0.0 || nv == 0.0) {
        std::cerr << "c_har err: div by 0" << std::endl;
        exit(84);
    }
    if (_nbV == 0)
        std::cerr << "zutte" << std::endl;
    if(_ari == 0)
        std::cerr << "flutte" << std::endl;
    if(nv == 0) {
        std::cerr << "c_har err: div by 0" << std::endl;
        exit(84);
    }
    _har = _nbV / (((_nbV - 1) / _har) + (1 / nv));
}

void n206::print()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "\tNumber of values:\t" << (int)_nbV << std::endl;
    std::cout << "\tStandard deviation:\t" << _dev << std::endl;
    std::cout << "\tArithmetic mean:\t" << _ari << std::endl;
    std::cout << "\tRoot mean square:\t" << _roo << std::endl;
    std::cout << "\tHarmonic mean:\t\t" << _har << std::endl << std::endl;
}


void calc(n206 &bonjour, double nv)
{
    bonjour.newval();
    bonjour.c_dev(nv);
    bonjour.c_ari(nv);
    bonjour.c_roo(nv);
    bonjour.c_har(nv);
    bonjour.print();
}

void call_206(char **av)
{
    n206 bonjour(av);
    std::string buff;
    double nextval = 0;

    while(42) {
        std::cout << "Enter next value: ";
        std::getline(std::cin, buff);
        if (std::cin.eof()) {
            std::cerr << "ctrl+D catched." << std::endl;
            break;
        }
        buff[buff.size()] = 0;
        if (strcasecmp("end", buff.c_str()) == 0)
            exit(0);
        nextval = atof(buff.c_str());
        if (nextval == 0.0) {
            std::cerr << "Bad value." << std::endl;
            continue;
        }
        calc(bonjour, nextval);
    }
    
}

bool iserror(char **av)
{
    if (atof(av[4]) < 0) {
        return true;
    }
    return false;
}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./206neutrinos n a h sd" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tn\tnumber of values" << std::endl;
    std::cout << "\ta\tarittmetic mean" << std::endl;
    std::cout << "\th\tharmonic mean" << std::endl;
    std::cout << "\tsd\tstandard deviation" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac != 5) {
        std::cerr << "invalid arguments" << std::endl;
        usage();
        return (84);
    }
    if (iserror(av)) {
        std::cerr << "invalid deviation" << std::endl;
        return 84;
    }
    call_206(av);
    return 0;
}