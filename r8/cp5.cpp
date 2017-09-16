#include <iostream>
#include <cstring>
using namespace std;

template<class T>
T max5(T tab[5]){
    T tab_max = tab[0];
    for (int i = 1; i < 5; ++i){
        if(tab[i] > tab_max)
            tab_max = tab[i];
    }
    return tab_max;
}

int main()
{
    int tab[5] = {2,35,12,52,12};
    cout << max5(tab);
    return 0;
}
