#include "sales.h"
#include <iostream>


void Sales::setSales(Sales & s, const double ar[], int n)
{
    double sum = 0;
    double min = ar[0];
    double max = ar[0];
    int i;
    for (i = 0; i < n; ++i)
    {
        if(min > ar[i])
            min = ar[i];
        if(max < ar[i])
        {
            //std::cout << "tak" << std::endl;
            max = ar[i];
        }
        s.sales[i] = ar[i];
        sum += s.sales[i];
    }
    for(; i < QUARTERS; ++i)
        s.sales[i] = 1;
    s.average = sum / n;
    s.min = min;
    s.max = max;
}

void Sales::setSales(Sales & s)
{
    std::cout << "Podaj sprzedaz dla " << QUARTERS << " sezonow: " << std::endl;
    double sal[QUARTERS];
    for (int i = 0; i < QUARTERS; ++i)
    {
        std::cout << "Sezon " << i+1 << ": ";
        while (!(std::cin >> sal[i]))
            std::cout << "Podaj liczbe: ";
    }
    setSales(s, sal, QUARTERS);
}

void Sales::showSales(const Sales & s)
{
    std::cout << "Sprzedaz: " << std::endl;
    std::cout.fixed;
    std::cout.precision(2);
    for (int i = 0; i < QUARTERS; ++i)
    {
        std::cout <<"Sezon " << i+1 << ": " << s.sales[i] << std::endl;
    }
    std::cout << "Srednia: " << s.average << std::endl;
    std::cout << "Najmniejszy zysk: " << s.min << std::endl;
    std::cout << "Najwiekszy zysk: " << s.max << std::endl;
}
