// stock20.h -- deklaracja klasy Stock z konstruktorami i destruktorem
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>
#include <iostream>

class Stock
{
    private:
        char * company;
        int shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }
    public:
        Stock();                // konstruktor domyślny
        Stock(const char * co, long n = 0, double pr = 0.0);
        ~Stock();               // "nic nierobiący" destruktor
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        friend std::ostream & operator<<(std::ostream & os, const Stock & s);
        const Stock & topval(const Stock & s) const;
};

#endif

