// stonewt1.h -- uzupełniona definicja klasy Stonewt
#ifndef STONEWT1_H_
#define STONEWT1_H_
#include <iostream>

class Stonewt
{
    private:
        enum {Lbs_per_stn = 14}; // liczba funtów na kamień
        int stone;               // masa w całych kamieniach
        double pds_left;         // reszta w funtach
        double pounds;           // masa w funtach
    public:
        Stonewt(double lbs);          // konstruktor dla funtów
        Stonewt(int stn, double lbs); // konstruktor dla kamieni i funtów
        Stonewt();                    // konstruktor domyślny
        ~Stonewt();
        friend std::ostream & operator<<(std::ostream & os,const Stonewt & st);
        // funkcje konwersji
        operator int() const;
        operator double() const;
        bool operator>(const Stonewt & st) const;
        bool operator<(const Stonewt & st) const;
        bool operator==(const Stonewt & st) const;
        Stonewt operator=(const Stonewt & st) const;
        template <typename T>Stonewt operator*(T mult) const
        {
            Stonewt result(pounds * mult);
            return result;
        }
        template <typename T>Stonewt operator/(T divider) const
        {
            Stonewt result(pounds / divider);
            return result;
        }
};
#endif

