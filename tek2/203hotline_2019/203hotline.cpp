/*
** EPITECH PROJECT, 2020
** 203hotline_2019
** File description:
** 203hotline
*/

#include "203hotline.hpp"

hotline::hotline(int ac, char **av)
{
    if (iserr(av, ac)){
        usage();
        exit(84);
    }
    for (int i = 0 ; i < 51 ; i++)
        binomArr[i] = 0;
    for (int i = 0 ; i < 51 ; i++)
        poissArr[i] = 0;
    overloadP = 0;
    overloadB = 0;
}

hotline::~hotline()
{
}

void hotline::pDoub()
{
}

double factoriel(int n)
{
   return (n > 1 ? (n * factoriel(n - 1)) : 1);
}

double factoriel(int a, int b)
{
    double ret = 1;

    for (int i = a ; i > (a - b) ; i--)
        ret = ret * i;
    return ret;
}

void hotline::doub()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(0);
    std::cout << k << "-combinations of a set of size " << n << std::endl;
    std::cout << (factoriel(n) / (factoriel(k) * factoriel(n - k))) << std::endl;
}

void hotline::binom()
{   
    double moy = ((d * 3500) / 8) / 3600;
    double m3 = moy / 3500;
    double first = 0;
    for (int i = 0 ; i < 51 ; i++) {
        first = factoriel(3500, i) / factoriel(i);
        binomArr[i] = first * pow(m3, i) * pow((1 - m3), (3500 - i));
        overloadB += (i < 26) ? binomArr[i] : 0;
    }
    overloadB = 1 - overloadB;
}

void hotline::poiss()
{
    double lambda = d / (8.0 * 3600.0 / 3500.0);

    for (int i = 0 ; i < 51 ; i++) {
        poissArr[i] = (pow(lambda, i) * std::exp(lambda * -1)) / factoriel(i);
        overloadP += (i < 26) ? poissArr[i] : 0;
    }
    overloadP = 1 - overloadP;
}

void hotline::printb(int64_t Bduration)
{
    std::cout << "Binomial distribution:" << std::endl;
    for (int i = 0 ; i < 51 ; i++) {
        if (((i % 5) == 4 || i == 50) && i != 0 && i != 1)
            std::cout << i << " -> " << binomArr[i] << std::endl;
        else
            std::cout << i << " -> " << binomArr[i] << "\t";
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    std::cout << "Overload: " << overloadB * 100 << "%" << std::endl;
    std::cout << "Computation time: 0." << Bduration * 10 << " ms" << std::endl;
}

void hotline::printp(int64_t Pduration)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    std::cout << "Poisson distribution:" << std::endl;
    for (int i = 0 ; i < 51 ; i++) {
        if (((i % 5) == 4 || i == 50) && i != 0 && i != 1)
            std::cout << i << " -> " << poissArr[i] << std::endl;
        else
            std::cout << i << " -> " << poissArr[i] << "\t";
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(1);
    std::cout << "Overload: " << overloadP * 100 << "%" << std::endl;
    std::cout << "Computation time: 0." << Pduration * 10 << " ms" << std::endl;
}

void hotline::printIt(int64_t Bduration, int64_t Pduration)
{
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    printb(Bduration);
    std::cout << std::endl;
    printp(Pduration);
}

void hotline::sing()
{
    auto start1 = std::chrono::high_resolution_clock::now();
    binom();
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto start2 = std::chrono::high_resolution_clock::now();
    poiss();
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto Bduration = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);
    auto Pduration = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);
    printIt(Bduration.count(), Pduration.count());
}

bool hotline::iserr(char **av, int nb)
{

    if (nb == 2) {
        d = atoi(av[1]);
        if (d < 1)
            return true;
    } else if (nb == 3) {
        std::string nstr(av[1]);
        std::string kstr(av[2]);
        if (nstr.find('.') != std::string::npos || kstr.find(".") != std::string::npos) {
            std::cerr << "No decimal number." << std::endl;
            return true;
        }
        n = atoi(av[1]);
        k = atoi(av[2]);
        if (k < 1 || n - 1 < k)
            return true;
    }
    return false;
}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./203hotline [n k | d]" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tn\tn value for the computation of C(n, k)" << std::endl;
    std::cout << "\tk\tk value for the computation of C(n, k)" << std::endl;
    std::cout << "\td\taverage duration of calls (in seconds)" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac == 2 || ac == 3) {
        hotline obj(ac, av);
        (ac == 2) ? obj.sing() : obj.doub();
        return (0);
    }
    std::cerr << "invalid arguments" << std::endl;
    usage();
    return (84);
}