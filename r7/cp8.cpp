//arrobj.cpp -- funkcje z obiektami typu array (C++11)
#include <iostream>
#include <array>
#include <string>

// dane stałe
const int Seasons = 4;
const char * seasons[4] =
{"Wiosna","Lato","Jesien","Zima"};

// funkcja modyfikująca tablicę typu array
void fill(double [],int);

// funkcja przetwarzająca tablicę typu array bez ingerencji w jej zawartość
void show(const double [], int);

int main()
{
    double expenses[4];
    fill(expenses,Seasons);
    show(expenses,Seasons);
    return 0;
}

void fill(double expenses[], int tableSize)
{
    using namespace std;
    for (int i = 0; i < tableSize; i++)
    {
        cout << "Podaj wydatki za okres >>" << seasons[i] << "<<: ";
        cin >> expenses[i];
    }
}
void show(const double expenses[], int tableSize)
{
    using namespace std;
    double total = 0.0;
    cout << "\nWYDATKI\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << seasons[i] << ": " << expenses[i] << " zl" << endl;
        total += expenses[i];
    }
    cout << "Lacznie wydatki roczne: " << total << " zl" << endl;
}
