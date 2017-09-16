#ifndef SALES_H_INCLUDED
#define SALES_H_INCLUDED

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

class Sales
{
    static const int QUARTERS = 4;
    double balance[QUARTERS];
    double average;
    double max;
    double min;
public:
    Sales(const double * ar[])
    {
        double minimum = ar[0];
        double maximum = ar[0];
        double sum = 0;
        for (int i = 0; i < QUARTERS; ++i)
        {
            if(minimum > ar[i])
                minimum = ar[i];
            if(maximum < ar[i])
                maximum = ar[i];
            balance[i] = ar[i];
            sum += ar[i];
        }
        min = minimum;
        max = maximum;
        average = sum / i+1;
    }

};


#endif // SALES_H_INCLUDED
