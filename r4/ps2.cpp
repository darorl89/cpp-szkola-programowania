#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<char,30> aktorzy;
    array<short,100> betsie;
    array<float,13> chuck;
    array<long double,64> dipsea;
    dipsea[0] = 3.21;
    cout << dipsea[0];
    return 0;
}
