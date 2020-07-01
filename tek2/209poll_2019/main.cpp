/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** main
*/

#include <iostream>
#include <cstring>

int bridge(char **av);

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./209poll pSize sSize p" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tpSize\tsize of the population" << std::endl;
    std::cout << "\tsSize\tsize of the sample (supposed to be representative)" << std::endl;
    std::cout << "\tp\tpercentage of voting intentions for a specific candidate" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac != 4) {
        std::cerr << "invalid arguement." << std::endl;
        usage();
        exit(84);
    }
    return bridge(av);
}