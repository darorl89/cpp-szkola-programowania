#include <iostream>
#include <array>
#include <cstdio>
#ifndef EOF
#define EOF (-1)
#endif
using namespace std;

struct car{
    string name;
    int year;
};

int main()
{
    int models = 0;
    cout << "Ile samochodow chcesz skatalogowac? ";
    cin >> models;
    car *p_cars = new car [models];
    int ch;
    char buffer[30];
    for (int i = 0; i < models && (ch = cin.get()) != -1 ; ++i){
        cout << "Samochod " << i+1 << endl;
        cout << "Prosze podac marke: ";
        cin.getline(buffer,100);
        p_cars[i].name = buffer;
        cout << "Rok produkcji? ";
        cin >> p_cars[i].year;
    }
    for (int i = 0 ; i < models ; ++i){
        cout << p_cars[i].year << " " << p_cars[i].name << endl;
    }
    return 0;
}
