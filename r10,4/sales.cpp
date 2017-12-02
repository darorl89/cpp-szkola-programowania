#include "sales.h"

Sales::Sales(const double ar[], int n)
{
    double minimum = ar[0];
    double maximum = ar[0];
    double sum = 0;
    int i;
    for (i = 0; i < n; ++i)
    {
        if(minimum > ar[i])
            minimum = ar[i];
        if(maximum < ar[i])
            maximum = ar[i];
        balance[i] = ar[i];
        sum += ar[i];
    }
    for (; i < QUARTERS; ++i)
    {
        balance[i] = 0;
    }
    min = minimum;
    max = maximum;
    average = sum / i;
}

void Sales::showSales() const
{
    cout << "Sprzedaz: " << endl;
    for (int i = 0; i < QUARTERS; ++i)
    {
        cout << "Kwartal " << i+1 << ": " << balance[i] << endl;
    }
    cout << "Srednia: " << average << endl;
    cout << "Wartosc najmniejsza: " << min << endl;
    cout << "Wartosc najwieksza: " << max << endl;
}
