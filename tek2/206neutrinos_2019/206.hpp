/*
** EPITECH PROJECT, 2020
** 206neutrinos_2019
** File description:
** 206
*/

#ifndef N206_HPP_
#define N206_HPP_

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

class n206
{
public:
    n206(char **av);
    ~n206();
    void c_ari(double nv);
    void c_roo(double nv);
    void c_dev(double nv);
    void c_har(double nv);
    void print();
    void newval();

    double g_ari() {return _ari;};
    double g_roo() {return _roo;};
    double g_dev() {return _dev;};
    double g_har() {return _har;};

private:
    /* data */
    double _nbV;
    double _dev;
    double _ari;
    double _roo;
    double _har;
};

n206::n206(char **av)
{
    try {
        _nbV = std::stoi(av[1]);
    } catch (std::exception const &e) {
            std::cerr << "number of value must be a positif positive";
            exit(84);
    }
    try {
        _ari = std::stof(av[2]);
    } catch (std::exception const &e) {
            std::cerr << "a is not a valid number";
            exit(84);
    }
    try {
        _har = std::stof(av[3]);
    } catch (std::exception const &e) {
            std::cerr << "h is not a valid number";
            exit(84);
    }
    try {
        _dev = std::stof(av[4]);
    } catch (std::exception const &e) {
            std::cerr << "sd is not a valid number";
            exit(84);
    }

    _roo = 0;
    
    if (_nbV < 0)
    {
        std::cerr << "number of value must be positive";
        exit(84);
    }

}

n206::~n206()
{
}

#endif /* !N206_HPP_ */
