/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** 208
*/

#ifndef N208_HPP_
#define N208_HPP_

#include <iostream>
#include <cstring>
#include <vector>

class N208
{
public:
    N208(char **av);
    ~N208();
private:
    std::vector<int> _O;
    int findmin(std::vector<int>);
};

N208::N208(char **av)
{
    try {
        for (int i = 1 ; i <= 9 ; i++) {
            int tmp = std::stoi(av[i]);
            if (tmp >= 0)
                _O.push_back(tmp);
            else {
                std::cerr << "number of value must be a positif integer" << std::endl;
                exit(84);
            }
        }
    } catch (std::exception const &e) {
            std::cerr << "number of value must be a positif integer" << std::endl;
            exit(84);
    }

    int tmp = 0;

    for (int i =0 ; i <= _O.size() ; i++) {
        tmp += _O[i];
    }
    if (tmp != 100) {
        std::cerr << "Addition of O is not equal to 100" << std::endl;
        exit(84);
    }
    while (_O[findmin(_O)] < 10) {
            int i = findmin(_O);
            if (i > 1 && (i + 1 >= _O.size() || _O[i - 1] < _O[i + 1]))
                _O[i - 1] += _O[i];
            else
                _O[i + 1] += _O[i];

            if (i == _O.size())
                _O.pop_back();
            else
                _O.erase(_O.begin()+i);
        std::cout << "rm " << i << std::endl;
    }
    for (int i =0 ; i <= _O.size() ; i++)
        std::cout <<_O[i] << std::endl;

}

N208::~N208()
{
}


#endif /* !208_HPP_ */
