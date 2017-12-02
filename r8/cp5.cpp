#include <iostream>
#include <cstring>
using namespace std;

const int MAXSIZE = 5;
template<class T>
T max5(T tab[], int size)
{
    T tab_max = tab[0];
    for (int i = 0; i < size; ++i)
    {
        if(tab[i] > tab_max)
            tab_max = tab[i];
    }
    return tab_max;
}

int main()
{
    int tab[MAXSIZE] = {2,35,12,52,12};
    double tab2[MAXSIZE] = {2.6, 32.12, 51.6, 42.4, 23.132};
    cout << max5(tab, MAXSIZE) << " " << max5(tab2, MAXSIZE);
    return 0;
}
