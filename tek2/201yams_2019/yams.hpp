/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** yams
*/

#ifndef YAMS_HPP_
#define YAMS_HPP_

#include <iostream>
#include <cstring>
#include <cmath>

enum toDoVal {
    PAIR,
    THREE,
    FOUR,
    FULL,
    STRAIGHT,
    YAMS,
};

class yams
{
private:
    int die[5];
    
    toDoVal todo;
    int val;
    int val2 = -1;
    bool ok = false;
    int nb = 0;
    double retProb = 0;
    int miss;

    int nb_nb(int num, int *arr);
    void full_algo();
    void straight_algo();
    void print();
    void check();
    void parse(char *toparse);
    bool diff();
    void setdouble();
public:
    yams(char **av);
    ~yams();
    void algo(char **av);
};

void usage();


#endif /* !YAMS_HPP_ */
