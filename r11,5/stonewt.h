// stonewt.h -- definicja klasy Stonewt
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt
{
    public:
        enum Measurement {STONE,POUNDS};
    private:
        enum {Lbs_per_stn = 14}; // liczba funtów na kamień
        int stone;               // masa w całych kamieniach
        double pds_left;         // reszta w funtach
        double pounds;           // masa w funtach
        Measurement measure;
    public:
        Stonewt(double lbs);          // konstruktor dla funtów
        Stonewt(int stn, double lbs); // konstruktor dla kamieni i funtów
        Stonewt();                    // konstruktor domyślny
        ~Stonewt();
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & st); // wyświetla masę
};
#endif

