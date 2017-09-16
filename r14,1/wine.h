#ifndef WINE_H_INCLUDED
#define WINE_H_INCLUDED

#include <iostream>
#include <valarray>

using std::cout;
using std::endl;

//typedef std::valarray<int> ArrayInt;
//typedef Pair<ArrayInt,ArrayInt> PairArray;
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

/*class Wine
{
    string name;
    PairArray pa;
public:
    Wine(const char * l, int y, const int yr[], const int bot[]);
    Wine(const char * l, int y);

};

void Pair::show() const
{
    cout << "Rocznik: " << year << ", ilosc: " << count << endl;
}

ostream & operator<<(ostream & os, Pair & p)
{
    os << year << ", " << count;
}

void change()
{
    cout << "Podaj rocznik";
    cin >> year;
    cout << "Podaj ilosc: ";
    cin >> count;
}*/
#endif // WINE_H_INCLUDED
