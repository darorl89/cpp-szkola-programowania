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

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt,ArrayInt> PairArray;

class Wine
{
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

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : label(l), year(y)
{
    for (int i = 0; i < y; ++i)
    {
        pa.first()[i] = yr[i];
        pa.second()[i] = bot[i];
    }
}

Wine::Wine(const char* l , int y ) : label(l), year(y)
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
    int y;
    int c;
    for (int i = 0; i < year; ++i)
    {
        cout << "Podaj rocznik: ";
        cin >> y;
        pa.first()[i] = y;
        cout << "Podaj liczbe butelek: ";
        cin >> c;
        pa.second()[i] = c;
    }
}

int Wine::Sum() const
{
    return pa.second().sum();
}

void Wine::Show() const
{
    cout << "Wino: " << label << endl;
    cout << "\t \t Rocznik \t Butelki" << endl;
    for (int i = 0; i < year; ++i)
    {
        int o = pa.first()[i];
        int s = pa.second()[i];
        cout << o << "\t" << s << endl;
    }
}

#endif // WINE_H_INCLUDED
