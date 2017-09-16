#ifndef WINEP_H_INCLUDED
#define WINEP_H_INCLUDED

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

class Wine : private string, private Pair<std::valarray<int>,std::valarray<int> >
{
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt,ArrayInt> PairArray;
    int year;
    Wine & operator=(const Wine &);
    Wine(const Wine &);
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l = "Undef", int y = 0);
    void GetBottles ();
    const string & Label() const {return (const string &) *this;}
    int Sum() const;
    void Show() const;
};

Wine::Wine(const char * l, int y, const int yr[], const int bot[]) : string(l), year(y), Pair(ArrayInt(y),ArrayInt(y))
{
    for (int i = 0; i < y; ++i)
    {
        Pair::first()[i] = yr[i];
        Pair::second()[i] = bot[i];
    }
}

Wine::Wine(const char * l , int y ) : string(l), year(y), Pair(ArrayInt(y),ArrayInt(y))
{
    for (int i = 0; i < year; ++i)
    {
        PairArray::first()[i] = 0;
        PairArray::second()[i] = 0;
    }
}

void Wine::GetBottles()
{
    cout << "Podaj dane o winie " << (const string &) *this << " dla " << year << " rocznikow: " << endl;
    for (int i = 0; i < year; ++i)
    {
        cout << "Podaj rocznik: ";
        cin >> PairArray::first()[i];
        cout << "Podaj liczbe butelek: ";
        cin >> PairArray::second()[i];
    }
}

int Wine::Sum() const
{
    return PairArray::second().sum();
}

void Wine::Show() const
{
    cout << "Wino: " << (const string &) *this << endl;
    cout << "\tRocznik \tButelki" << endl;
    for (int i = 0; i < year; ++i)
    {
        cout << "\t" << PairArray::first()[i] << " \t \t" << PairArray::second()[i] << endl;
    }
}

#endif // WINEP_H_INCLUDED
