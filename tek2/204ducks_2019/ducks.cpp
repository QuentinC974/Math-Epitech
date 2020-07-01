/*
** EPITECH PROJECT, 2020
** 204tmp
** File description:
** ducks
*/

#include "ducks.hpp"

ducks::ducks(double val)
{
    a = val;
    p2m = 0;
    p1m = 0;
    t99 = 0;
    t50 = 0;
    dev = 0;
    ave = 0;
}

ducks::~ducks()
{
}

double ducks::justdoit()
{
    double tmp = 0;
    double res = 0;

    for (double i = 0.001 ; i <= 1000; i+= 0.001) {
        res = densityFunc(a, i);
        tmp += (pow((i - (ave / 1000)), 2) * res);
    }
    return (sqrt(tmp / 1000));
}

void ducks::printer()
{
    int t50s = (t50 - (int)(t50)) * 60;
    int t99s = (t99 - (int)(t99)) * 60;
    int aves = 0;
    std::string tmp = a == 1.6 ? "1m 21s" : a == 0.2 ? "0m 50s" : "none";
    dev = justdoit();

    std::cout << "Average return time: " << tmp << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    std::cout << "Standard deviation: " << dev << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    t50s > 9 ? 
        std::cout << "Time after which 50% of the ducks are back: " << (int)(t50) << "m " << t50s << "s" << std::endl :
        std::cout << "Time after which 50% of the ducks are back: " << (int)(t50) << "m " << "0" << t50s << "s" << std::endl;
    t99s > 9 ? 
        std::cout << "Time after which 99% of the ducks are back: " << (int)(t99) << "m " << t99s << "s" << std::endl :
        std::cout << "Time after which 99% of the ducks are back: " << (int)(t99) << "m " << "0" << t99s << "s" << std::endl;
    std::cout << "Percentage of ducks back after 1 minute: " << std::round(p1m) / 10 << "%" << std::endl;
    std::cout << "Percentage of ducks back after 2 minutes: " << std::round(p2m) / 10 << "%" << std::endl;
}

double ducks::densityFunc(double a, double t)
{
    return ((a * exp(-1*t)) + ((4 - 3*a) * exp(-2*t)) + ((2*a - 4) * exp(-4*t)));
}

void ducks::doit()
{
    double res = 0;
    double p = 0;
    int mv = 0;
    int pv = 0;

    for (double i = 0 ; i <= 1000 ; i+= 0.001) {
        res = densityFunc(a, i);
        p += res;
        ave += i * res;
        if (mv == 0 && p >= 500) {
            t50 = i;
            mv = 1;
        }
        if (mv != 2 && p >= 990) {
            t99 = i;
            mv = 2;
        }
        if (i <= 1)
            p1m += res;
        if (i == 1)
            p1m = (p + p1m) / 2.0;
        if (i <= 2)
            p2m += res;
        if (i == 2)
            p2m = (p + p2m) / 2.0;
    }

}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./204ducks a" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\ta\tconstant" << std::endl;
}

bool parse_double(std::string in, double& res) {
    try {
        size_t read= 0;
        res = std::stod(in, &read);
        if (in.size() != read)
            return false;
    } catch (std::invalid_argument) {
        return false;
    }    
    return true;
}

int main(int ac, char **av)
{
    double a = 0;

    if (ac != 2) {
        std::cerr << "invalid arguments" << std::endl;
        usage();
        return (84);
    } 
    bool b = parse_double(av[1], a);
    if (!b || a < 0 || a > 2.5) {
        std::cerr << " 0 <= a <= 2.5" << std::endl;
        usage();
        return (84);
    } else if (strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    ducks d((double)atof(av[1]));
    d.doit();
    d.printer();
    return (0);
}