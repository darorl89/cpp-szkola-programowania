// stonewt.cpp -- implementacje metod klasy Stonewt z funkcjami konwersji
#include <iostream>
using std::cout;
#include "stonewt1.h"

// konstruuje obiekt Stonewt z wartości typu double
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn; // dzielenie całkowite
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// konstruuje obiekt Stonewt z liczby kamieni i funtów
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt() // konstruktor domyślny, zeruje obiekt
{
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() // destruktor
{
}
// pokazuje masę w kamieniach
std::ostream & operator<<(std::ostream & os,const Stonewt & st)
{
    os << "Masa: " << st.pounds << " funtow :)" << std::endl;
    return os;
}
// funkcje konwersji
Stonewt::operator int() const
{
    return int (pounds + 0.5);
}

Stonewt::operator double() const
{
    return pounds;
}

bool Stonewt::operator<(const Stonewt & st) const
{
    if(pounds < st.pounds)
        return true;
    else
        return false;
}

bool Stonewt::operator>(const Stonewt & st) const
{
    return !(operator<(st));
}

bool Stonewt::operator==(const Stonewt & st) const
{
    if (pounds == st.pounds)
        return true;
    else
        return false;
}

Stonewt Stonewt::operator=(const Stonewt& st) const
{
    Stonewt result(st.pounds);
    return result;
}



