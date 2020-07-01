/*
** EPITECH PROJECT, 2020
** MATH
** File description:
** demo
*/

#include "207.hpp"

template <class T>
T car(T a) {return (a * a);}

template <class T>
T addit(std::vector<T> v)
{
    T ret = 0;

    for (int i = 0 ; i < v.size() ; i++)
        ret += v[i];
    return ret;
}
template <class T>
T mabs(T a) {return a < 0 ? a * -1 : a;}


void demo::print()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    std::cout << "Country: ";
    for (int i = 0 ; i < _pos.size() ; i++) {
        std::cout << _names[_pos[i]] << ' ';
    }
    std::cout << std::endl << "Fit1" << std::endl;
    std::cout << "\tY = " << _FX1 / 1000000 << " X - " << mabs(_FY1 / 1000000) << std::endl;
    std::cout << "\tRoot-mean-square deviation: " << _rms1 / 1000000 << std::endl;
    std::cout << "\tPopulation in 2050: " << ((_FX1 * 2050) - mabs(_FY1)) / 1000000 << std::endl;
    std::cout << "Fit2" << std::endl;
    std::cout << "\tX = " << _FX2 * 1000000 << " Y + " << _FY2 << std::endl;
    std::cout << "\tRoot-mean-square deviation: " << _rms2 / 1000000 << std::endl;
    std::cout << "\tPopulation in 2050: " << ((2050 - _FY2)/ _FX2) / 1000000 << std::endl;
    std::cout << std::setprecision(4);
    std::cout << "Correlation: " << _cor << std::endl;
}

std::vector<std::string> explode(std::string &s, char delim)
{
    std::vector<std::string> result;
    if (s[0] == ' ')
        s.erase(0, 1);
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim);)
        result.push_back(std::move(token));
    return result;
}

std::vector<std::vector<std::string> > demo::openit()
{
    std::vector<std::vector<std::string> > ret;
    std::string line;
    std::ifstream myfile("207demography_data.csv");
    bool done = false;
    
    if (myfile.is_open())
    {
        while (std::getline(myfile,line) )
        {
            if (done) {
                ret.push_back(explode(line, ';'));
            }
            done = true;
        }
        myfile.close();
    } else std::cerr << "Unable to open file"; 
    return ret;
}

std::vector<std::pair<std::string, std::vector<int> > > demo::setupData(std::vector<std::vector<std::string> >tmp)
{
    std::vector<std::pair<std::string, std::vector<int> > > ret;
    std::vector<int> value;
     
     for (int i = 0 ; i < tmp.size() ; i++) {
        for (int j = 2 ; j < tmp[i].size() ; j++) {
            value.push_back(atoi(tmp[i][j].c_str()));
        }
        ret.push_back(std::make_pair(tmp[i][1], value));
        value.clear();
        _names.push_back(tmp[i][0]);
     }
    return ret;
}

std::pair<std::string, std::vector<int> > demo::seachfor(std::string that)
{
    std::vector<int> null_vector;

    for (int i = 0 ; i < _data.size() ; i++) {
        if (that == _data[i].first)
            return(_data[i]);
    }
    return (std::make_pair(nullptr, null_vector));
}

bool demo::isin(std::string that)
{
    std::vector<int> null_vector;

    for (int i = 0 ; i < _data.size() ; i++) {
        if (that == _data[i].first)
            return(true);
    }
    return (false);
}

void demo::doit(std::vector<std::pair<std::string, bool> > pCodes)
{
    _data = setupData(openit());
    
    for (int i = 0 ; i < pCodes.size() ; i++) {
        for (int j = 0 ; j < _data.size() ; j++) {
            if (pCodes[i].first == _data[j].first) {
                pCodes[i].second = true;
                _toUse.push_back(_data[j]);
                _pos.push_back(j);
            }
        }
        if (pCodes[i].second == false) {
            std::cerr << pCodes[i].first << " is not a valid country code" << std::endl;
            exit(84);
        }
    }

    calc();

    print();
}

void demo::average()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(0);

    
    
    int tmp = 0;
    for (int j = 0 ; j < _toUse[0].second.size() ; j++) {
        tmp = 0;
        for (int i = 0 ; i < _toUse.size() ; i++) {
            tmp += _toUse[i].second[j];
        }
        _average.push_back(static_cast<double>(tmp)); //  / _toUse.size()
    }
    for (double i = 1960 ; i < 2018 ; i += 1.0)
        _years.push_back(i);

    // for (int i = 0 ; i < _average.size() ; i += 1)
    //     std::cout << _average[i] << std::endl;
    _aveYear = addit(_years) / (double)_years.size();
    _avePopu = addit(_average) / (double)_average.size();

}

void demo::initCovariance()
{
    _cov = 0;
    for (int i = 0 ; i < _average.size() ; i++)
        _cov += (_average[i] - _avePopu) * (_years[i] - _aveYear);
    _cov /= _average.size();

}

void demo::calc()
{
    average();
    initCovariance();
    
    for (int i = 0 ; i < _average.size() ; i++)
        _popM.push_back(car(_average[i] - _avePopu));
    for (int i = 0 ; i < _average.size() ; i++)
        _yeaM.push_back(car(_years[i] - _aveYear));

    double tmpX = sqrt(addit(_popM) / _popM.size());
    double tmpY = sqrt(addit(_yeaM) / _yeaM.size());

    _cor = _cov / (tmpX * tmpY);

    _FX1 = _cov / car(tmpY);
    _FY1 = _avePopu - _FX1 * _aveYear;

    _FX2 = _cov / car(tmpX);
    _FY2 = _aveYear - _FX2 * _avePopu;

    double b1 = mabs(_FY1);
    double b2 = mabs(_FY2);

    for (int i = 0 ; i < _years.size() ; i++)
        _xM.push_back(_FX1 * _years[i] - b1);
    for (int i = 0 ; i < _years.size() ; i++)
        _yM.push_back((_years[i] - b2)/ _FX2);
    
    double s1 = 0;
    double s2 = 0;
    
    for (int i = 0 ; i < _xM.size() ; i++)
        s1 += car(_xM[i] - _average[i]);
    _rms1 = sqrt(s1 / _xM.size());
    for (int i = 0 ; i < _yM.size() ; i++)
        s2 += car(_yM[i] - _average[i]);
    _rms2 = sqrt(s2 / _yM.size());



}



void bridge(std::vector<std::pair<std::string, bool> > pCodes)
{
    demo toto;
    toto.doit(pCodes);
}

void usage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./207demography code [...]" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tcode\tcountry code" << std::endl;
}

int main(int ac, char **av)
{
    std::vector<std::pair<std::string, bool> > pCodes;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage();
        return (0);
    }
    if (ac < 2) {
        std::cerr << "invalid arguement." << std::endl;
        usage();
        exit(84);
    }

    for (int i = 1 ; i < ac ; i++)
        pCodes.push_back(std::make_pair(av[i], false));

    for (int i = 0 ; i < pCodes.size() ; i++) {
        if (pCodes[i].first.size() != 3){
            std::cerr << pCodes[i].first << " is not a country code." << std::endl;
            exit(84);
        }
    }
    bridge(pCodes);
}