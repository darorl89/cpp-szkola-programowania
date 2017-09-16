#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "vect.h"

int main()
{
    const char * file_name = "kroki.txt";
    std::ofstream fout;
    fout.open(file_name);
    if(!fout.is_open())
    {
        std::cout << "Nie moge otworzyc " << file_name << std::endl;
        exit(EXIT_FAILURE);
    }
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result;
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
    while(cin >> target)
    {
        fout << "Dystans do przejscia: " << target << ", ";
        cout << "Podaj dlugosc kroku: ";
        if(!(cin >> dstep))
            break;
        fout << "dlugosc kroku: " << dstep << endl;
        while(result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            ++steps;
            fout << "Krok nr " << steps << " " << result << endl;
        }
        fout << "Po " << steps << " krokach delikwent osiagnal polozenie: " << endl;
        result.rect_mode();
        fout << result;
        result.polar_mode();
        fout << ", czyli: " << result << endl;
        fout << "Srednia dlugosc kroku pozornego = " << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Podaj dystans do przejscia (k, aby zakonczyc): ";
    }
    return 0;
}
