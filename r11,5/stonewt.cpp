// stonewt.cpp -- implementacje metod klasy Stonewt
#include "stonewt.h"
using std::cout;

// konstruuje obiekt Stonewt z wartości typu double
Stonewt::Stonewt(double lbs)
{
    measure = POUNDS;
    stone = int (lbs) / Lbs_per_stn; // dzielenie całkowite
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// konstruuje obiekt Stonewt z liczby kamieni i funtów
Stonewt::Stonewt(int stn, double lbs)
{
    measure = STONE;
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt() // konstruktor domyślny, zeruje obiekt
{
    measure = POUNDS;
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() // destruktor
{
}
// pokazuje masę w kamieniach
std::ostream & operator<<(std::ostream & os, const Stonewt & st)
{
    if (st.measure == Stonewt::STONE)
        cout << st.stone << " kamieni, " << st.pds_left << " funtów\n";
    else if (st.measure == Stonewt::POUNDS)
        cout << st.pds_left  << " funtow\n";
    else
        cout << "Nieprawidlowa miara :(";
}
