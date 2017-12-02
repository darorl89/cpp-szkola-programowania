#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Sales
{
public:
    static const int QUARTERS = 4;
private:
    double balance[QUARTERS];
    double average;
    double max;
    double min;
public:

    Sales(const double ar[], int n);
    void showSales() const;
};


#endif // SALES_H_INCLUDED
