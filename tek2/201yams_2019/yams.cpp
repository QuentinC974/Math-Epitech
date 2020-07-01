/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** yams
*/

#include <iomanip>
#include "yams.hpp"

yams::yams(char **av)
{
    for (int i = 0; i < 5 ; i++)
        die[i] = atoi(av[i + 1]);
    if ((die[1] < 0 || die[1] > 6)
        || (die[2] < 0 || die[2] > 6)
        || (die[3] < 0 || die[3] > 6)
        || (die[4] < 0 || die[4] > 6)
        || (die[0] < 0 || die[0] > 6)) {
        std::cerr << "invalid die" << std::endl;
        usage ();
        exit(84);
    }
    if (nb_nb(0, die) != 5 && nb_nb(0, die) != 0) {
        usage ();
        exit(84);
    }
    parse(av[6]);
}

yams::~yams()
{
}

void yams::parse(char *toparse)
{
    std::string parse = toparse;
    if (parse.find("pair") != std::string::npos){
        if (parse.size() == 6) {
            val = toparse[5] - 48;
            todo = PAIR;
            if (val >= 1 && val <= 6)
                ok = true;
        }
    }
    if (parse.find("three") != std::string::npos){
        if (parse.size() == 7) {
            val = toparse[6] - 48;
            todo = THREE;
            if (val >= 1 && val <= 6)
                ok = true;
        }
    }
    if (parse.find("four") != std::string::npos){
        if (parse.size() == 6) {
            val = toparse[5] - 48;
            todo = FOUR;
            if (val >= 1 && val <= 6)
                ok = true;
        }
    }
    if (parse.find("full") != std::string::npos){
        if (parse.size() == 8) {
            val = toparse[5] - 48;
            val2 = toparse[7] - 48;
            todo = FULL;
            if (val >= 1 && val <= 6 && val != val2 && val2 >= 1 && val2 <= 6)
                ok = true;
        }
    }
    if (parse.find("straight") != std::string::npos){
        if (parse.size() == 10) {
            val = toparse[9] - 48;
            todo = STRAIGHT;
            ok = true;
            if (val != 5 && val != 6)
                ok = false;
        }
    }
    if (parse.find("yams") != std::string::npos){
        if (parse.size() == 6) {
            val = toparse[5] - 48;
            todo = YAMS;
            if (val >= 1 && val <= 6)
                ok = true;
        }
    }
    if (!ok) {
        std::cerr << "invalid combination" << std::endl;
        usage();
        exit(84);
    }
}

double factoriel(int n)
{
   return (n > 1 ? (n * factoriel(n - 1)) : 1);
}

void yams::print()
{
    std::string Ido;

    std::cout.precision(2);
    std::cout << std::fixed;
    if (todo == PAIR)
        Ido = "pair";
    if (todo == THREE)
        Ido = "three-of-a-kind";
    if (todo == FOUR)
        Ido = "four-of-a-kind";
    if (todo == FULL)
        Ido = "full";
    if (todo == STRAIGHT)
        Ido = "straight";
    if (todo == YAMS)
        Ido = "yams";
    if (todo != FULL)
        std::cout << "Chances to get a " << val << " " << Ido << ": " << retProb << "%" <<std::endl;
    else
        std::cout << "Chances to get a " << val << " " << Ido << " of " << val2 << ": " << retProb << "%" <<std::endl;
}

void yams::check()
{
    for (int i = 0 ; i < 5 ; i++)
        if (die[i] != val)
            nb++;
    if (todo == PAIR && nb < 3)
        retProb = 100;
    if (todo == THREE && nb < 2)
        retProb = 100;
    if (todo == FOUR && nb < 1)
        retProb = 100;
    if (todo == YAMS && nb == 0)
        retProb = 100;
    miss = 5 - nb;
    // std::cout << "find: " << nb << std::endl;
}

int yams::nb_nb(int num, int *arr)
{
    int rnb = 0;
    for (int i = 0 ; i < 5 ; i++)
        if (arr[i] == num)
            rnb++;
    return rnb;
}

void yams::full_algo()
{
    int nb1 = nb_nb(val, die);
    int nb2 = nb_nb(val2, die);
    double test = 0;
    double test2 = 2;

    if (nb1 == 3 && nb2 == 2)
        retProb = 100;
    else {
        if (nb1 >= 3)
            retProb = (1 / pow(6, (2 - nb2))) * 100;
        else if (nb2 >= 2)
            retProb = (1 / pow(6, (3 - nb1))) * 100;
        else {
            test = factoriel(5 - nb1 - nb2) / (factoriel((5 - nb1 - nb2) - (3 - nb1)) * factoriel(3 - nb2));
            test2 = (factoriel(2 - nb2) / (factoriel(2 - nb2 - 2 - nb2) * factoriel(2 -nb2)));
            retProb = (test * test2) / pow(6, (5 - nb1 - nb2)) * 100;
            if (nb1 != nb2) {
                for (int i = 2; i <= 5 - nb1 - nb2; i++) {
                    retProb *= i;
                }
            }
        }
    }
}

bool yams::diff()
{
    int nombre = 0;

    for (int i = 0 ; i < 5 ; i++)
    {
        for (int j = 0 ; j < 5 ; j++) {
            if (i != j)
                if (die[i] != die [j])
                    nombre++;
        }
    }
    return (nombre == 20 ? true : false);
}

void yams::setdouble()
{
    int tab[5] = {0, 0, 0, 0, 0};

    for (int i = 0 ; i < 5 ; i++)
        tab[i] = die[i];
    for (int i = 0 ; i < 5 ; i++)
    {
        for (int j = 0 ; j < 5 ; j++) {
            if (i != j)
                if (tab[i] == tab [j])
                    tab[i] = 0;
        }
    }
    for (int i = 0 ; i < 5 ; i++) {
        if (val == 5 && tab[i] == 6)
            die[i] = 0;
        else if (val == 6 && tab[i] == 1)
            die[i] = 0;
        else
            die[i] = tab [i];
    }
}

void yams::straight_algo()
{
    int j = 0;
    int nb = nb_nb(val, die);
    double test = 0;
    int want = 5;
    setdouble();

    miss = 5 - nb;
    if (diff()) {
        if (val == 5 && die[1] < 6 && die[2] < 6 && die[3] < 6 && die[4] < 6 && die[0] < 6)
                retProb = 100;
        if (val == 6 && die[1] > 1 && die[2] > 1 && die[3] > 1 && die[4] > 1 && die[0] > 1)
                retProb = 100;
    }
    nb = nb_nb(0, die);
    if (retProb == 0) {
        for (int i = 5 - (5 - nb) ; i != (5 - (5 - nb) + 1) ; i++) {
            test = factoriel(nb) / (factoriel(nb - i) * factoriel(i));
            retProb += test * pow((double)1 / (double)6, i) *
            pow(((double)5 / (double)6), 5 - (5 - nb) - i) * 100;
        }
        for (int i = 2; i <= nb; i++)
            retProb *= i;
    }
}

void yams::algo(char **av)
{
    int want;
    check();
    if (todo == PAIR)
        want = 2;
    if (todo == THREE)
        want = 3;
    if (todo == FOUR)
        want = 4;
    if (retProb == 0 && todo != STRAIGHT && todo != FULL && todo != YAMS) {
        for (int i = want - miss ; i != 5 - miss + 1 ; i++) { 
            retProb += (factoriel(5 - miss) / (factoriel(5 - miss - i) * factoriel(i))) *
            (pow((double)1/(double)6, i) * pow((double)5 / (double)6, 5 - miss - i)) * 100;
        }
    } else if (retProb == 0 && todo == YAMS) {
        retProb = (1 / pow(6, (5 - miss))) * 100;
    } else if (retProb == 0 && todo == FULL) {
        full_algo();
    } else if (retProb == 0 && todo == STRAIGHT) {
        straight_algo();
    }
    print();
}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./201yams d1 d2 d3 d4 d5 c" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\td1\tvalue of the first die (0 if not thrown)" << std::endl;
    std::cout << "\td2\tvalue of the second die (0 if not thrown)" << std::endl;
    std::cout << "\td3\tvalue of the third die (0 if not thrown)" << std::endl;
    std::cout << "\td4\tvalue of the fourth die (0 if not thrown)" << std::endl;
    std::cout << "\td5\tvalue of the fifth die (0 if not thrown)" << std::endl;
    std::cout << "\tc\texpected combination" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 7) {
        if (ac == 2 && strcmp(av[1], "-h") == 0) {
            usage();
            return(0);
        }
        usage();
        return(84);
    }
    yams game(av);
    game.algo(av);
    return (0);
}
