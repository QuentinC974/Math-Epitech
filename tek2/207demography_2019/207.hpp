/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** 207
*/

#ifndef D207_HPP_
#define D207_HPP_

#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility> 
#include <fstream>

class demo
{
public:
    demo(/* args */);
    ~demo();
    std::vector<std::pair<std::string, std::vector<int> > > setupData(std::vector<std::vector<std::string> >tmp);
    std::vector<std::vector<std::string> > openit();
    void doit(std::vector<std::pair<std::string, bool> > pCodes);
    std::pair<std::string, std::vector<int> > seachfor(std::string that);
    bool isin(std::string that);
    void print();
    void calc();

private:
    void average();
    void initCovariance();
    std::vector<std::pair<std::string, std::vector<int> > > _data;
    std::vector<std::pair<std::string, std::vector<int> > > _toUse;

    //CALC
    double _aveYear;
    double _avePopu;
    std::vector<double> _years;
    std::vector<double> _average;
    std::vector<double> _popM;
    std::vector<double> _yeaM;
    double _FX1;
    double _FX2;
    double _FY1;
    double _FY2;
    double _cov;
    double _cor;
    double _rms1;
    double _rms2;

    std::vector<double> _xM;
    std::vector<double> _yM;



    //display country name
    std::vector<int> _pos;
    std::vector<std::string> _names;


};

demo::demo(/* args */)
{
}

demo::~demo()
{
}


#endif /* !D207_HPP_ */
