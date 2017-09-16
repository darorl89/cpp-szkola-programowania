#include <iostream>
#include <array>
#include <cstdio>
using namespace std;
const int months = 12;
int main()
{
    int sold,sales[months],sum;
    sum = sold = 0;
    for (int i = 0 ; i < months ; ++i){
        cout << "Podaj liczbe sprzedanych sztuk w " << i+1 << " miesiacu: ";
        cin >> sold;
        sum+=sold;
    }
    cout << "Suma sprzedanych ksiazek wynosi: " << sum;
    return 0;
}
