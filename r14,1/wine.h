#ifndef WINE_H_INCLUDED
#define WINE_H_INCLUDED

#include <iostream>
#include <valarray>
#include <cstring>

using std::cout;
using std::endl;
using std::string;
using std::cin;


template<typename T1, typename T2>
class Pair
{
    T1 a;
    T2 b;
public:
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) {}
    Pair() {}
    T1 first() const {return a;}
    T2 second() const {return b;}
    T1 & first();
    T2 & second();
};

template<typename T1, typename T2>
T1 & Pair<T1,T2>::first() {return a;}
template<typename T1, typename T2>
T2 & Pair<T1,T2>::second() {return b;}

class Wine
{
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt,ArrayInt> PairArray;
    string label;
    int year;
    PairArray pa;
    Wine & operator=(const Wine &);
    Wine(const Wine &);
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l = "Undef", int y = 0);
    void GetBottles ();
    const string & Label() const {return label;}
    int Sum() const;
    void Show() const;
};

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : label(l), year(y), pa(ArrayInt(y),ArrayInt(y))
{
    for (int i = 0; i < y; ++i)
    {
        pa.first()[i] = yr[i];
        pa.second()[i] = bot[i];
    }
}

Wine::Wine(const char* l , int y ) : label(l), year(y), pa(ArrayInt(y),ArrayInt(y))
{
    for (int i = 0; i < year; ++i)
    {
        pa.first()[i] = 0;
        pa.second()[i] = 0;
    }
}

void Wine::GetBottles()
{
    cout << "Podaj dane o winie " << label << " dla " << year << " rocznikow: " << endl;
    for (int i = 0; i < year; ++i)
    {
        cout << "Podaj rocznik: ";
        cin >> pa.first()[i];
        cout << "Podaj liczbe butelek: ";
        cin >> pa.second()[i];
    }
}

int Wine::Sum() const
{
    return pa.second().sum();
}

void Wine::Show() const
{
    cout << "Wino: " << label << endl;
    cout << "\tRocznik \tButelki" << endl;
    for (int i = 0; i < year; ++i)
    {
        cout << "\t" <<pa.first()[i] << " \t \t" << pa.second()[i] << endl;
    }
}

#endif // WINE_H_INCLUDED
