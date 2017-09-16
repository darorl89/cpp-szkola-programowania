#include <iostream>
#include "complex0.h"

using namespace std;

int main()
{
    Complex a(3.0,4.0);
    Complex c;
    cout << "Podaj liczbe zespolona (k, aby zakonczyc)\n";
    cin >> c;
    cout << c;
    return 0;
}
