/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** 208
*/

#include "208.hpp"


int N208::findmin(std::vector<int> v)
{
    int min = 100;
    int i = 0;
    for (; i < v.size() ; i++) {
        if (v[i] < min)
            min = v[i];
    }
    return i;
}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tOi\tsize of the observed class" << std::endl;
}

void do208(char** av)
{
    N208 Will(av);
    std::cout << "OK" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac != 10) {
        std::cerr << "invalid arguments" << std::endl;
        usage();
        return (84);
    }
    do208(av);
    return 0;
}