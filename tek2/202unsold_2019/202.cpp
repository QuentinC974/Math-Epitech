/*
** EPITECH PROJECT, 2020
** 202unsold_2019
** File description:
** 202
*/

#include "202.hpp"

unsold::unsold(char **av)
{
    a = atoi(av[1]);
    b = atoi(av[2]);
}

unsold::~unsold()
{
}

void unsold::joinLawPrint()
{
    std::cout << "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law" << std::endl;
    for (int i = 0 ; i < 6 ; i++) {

        if (i == 5)
            std::cout << "X law\t" << std::flush;
        else
            std::cout << "Y=" << (i + 1) * 10 << "\t" << std::flush;
        for (int j = 0 ; j < 6 ; j++) {
            if (j != 5)
                std::cout << JLarray[i][j] << "\t" << std::flush;
            else
                std::cout << JLarray[i][j] << std::flush;
        }
        std::cout << std::endl;
    }

}

double unsold::JLcal(int x, int y)
{
    return (((a - x) * (b - y)) / (((5 * a) - 150) * ((5 * b) - 150)));
}

void unsold::joinLaw()
{
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++)
            JLarray[i][j] = JLcal((j + 1) * 10, (i + 1) * 10);
    }
    for (int i = 0 ; i < 5 ; i++) {
        JLarray[5][i] = JLarray[0][i] + JLarray[1][i] + JLarray[2][i] + JLarray[3][i] + JLarray[4][i];
        JLarray[i][5] = JLarray[i][0] + JLarray[i][1] + JLarray[i][2] + JLarray[i][3] + JLarray[i][4];
    }
    JLarray[5][5] = JLarray[5][0] + JLarray[5][1] + JLarray[5][2] + JLarray[5][3] + JLarray[5][4];
}


void unsold::dashlane()
{
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
}

void unsold::marginalLawPrint()
{
    std::cout << "z\t20\t30\t40\t50\t60\t70\t80\t90\t100" <<std::endl;
    std::cout << "p(Z=z)\t";
    for (int j = 0 ; j < 9 ; j++) {
        if (j != 8)
            std::cout << Marray[j] << "\t" << std::flush;
        else
            std::cout << Marray[j] << std::flush;
    }
    std::cout << std::endl;
}

void unsold::marginalLaw()
{
    Marray[0] = JLarray[0][0];
    Marray[1] = JLarray[1][0] + JLarray[0][1];
    Marray[2] = JLarray[2][0] + JLarray[1][1] + JLarray[0][2];
    Marray[3] = JLarray[3][0] + JLarray[2][1] + JLarray[1][2] + JLarray[0][3];
    Marray[4] = JLarray[4][0] + JLarray[3][1] + JLarray[2][2] + JLarray[1][3] + JLarray[0][4];
    Marray[5] = JLarray[4][1] + JLarray[2][3] + JLarray[3][2] + JLarray[1][4];
    Marray[6] = JLarray[4][2] + JLarray[3][3] + JLarray[2][4];
    Marray[7] = JLarray[4][3] + JLarray[3][4];
    Marray[8] = JLarray[4][4];
}

void unsold::espevarPrint()
{
    std::cout.precision(1);
    std::cout << std::fixed;
    std::cout << "expected value of X:\t" << Earray[0] << std::endl;
    std::cout << "variance of X:\t\t" << Varray[0] << std::endl;
    std::cout << "expected value of Y:\t" << Earray[1] << std::endl;
    std::cout << "variance of Y:\t\t" << Varray[1] << std::endl;
    std::cout << "expected value of Z:\t" << Earray[2] << std::endl;
    std::cout << "variance of Z:\t\t" << Varray[2] << std::endl;

}

void unsold::espevar()
{
    for (int i = 0 ; i < 3 ; i++) {
        Earray[i] = 0;
        Varray[i] = 0;
    }
    for (int i = 0 ; i < 5 ; i++)
        Earray[0] += JLarray[5][i] * ((i + 1) * 10);
    for (int i = 0 ; i < 5 ; i++)
        Earray[1] += JLarray[i][5] * ((i + 1) * 10);
    for (int i = 0 ; i < 9 ; i++)
        Earray[2] += Marray[i] * ((i + 2) * 10);
    for (int i = 0 ; i < 5 ; i++)
        Varray[0] += JLarray[5][i] * pow(((i + 1) * 10) - Earray[0], 2);
    for (int i = 0 ; i < 5 ; i++)
        Varray[1] += JLarray[i][5] * pow((i + 1) * 10  - Earray[1], 2);
    for (int i = 0 ; i < 9 ; i++)
        Varray[2] += Marray[i] * pow((i + 2) * 10  - Earray[2], 2);
}

void unsold::print()
{
    std::cout.precision(3);
    std::cout << std::fixed;
    dashlane();
    joinLawPrint();

    dashlane();
    marginalLawPrint();

    dashlane();
    espevarPrint();
    dashlane();
}

void myUnsold(char **av)
{
    unsold myUnsold(av);
    
    myUnsold.joinLaw();
    myUnsold.marginalLaw();
    myUnsold.espevar();
    myUnsold.print();

}

    

bool iserr(char **av)
{
    if (atoi(av[1]) < 50){
        std::cerr << "a must be an integers greater than 50." << std::endl;
        return true;
    }
    if (atoi(av[2]) < 50){
        std::cerr << "b must be an integers greater than 50." << std::endl;
        return true;
    }
    return false;
}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./202unsold a b" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\ta constant computed from past results" << std::endl;
    std::cout << "\tb constant computed from past results" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac != 3) {
        std::cerr << "invalid arguments" << std::endl;
        usage();
        return (84);
    }
    if (iserr(av)){
        usage();
        return (84);
    }

    myUnsold(av);


    return (0);
}